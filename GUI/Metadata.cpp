#include "stdafx.h"
#include "Metadata.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using boost::property_tree::ptree;

// where the logic for the metadata creation will go
Metadata::Metadata(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.Save, SIGNAL(clicked()), this, SLOT(saveMetadata()));

	FILE* fp = fopen("C:/Users/hmunoz/Documents/Visual Studio 2015/Projects/Thesis/GUI/Resources/userMetadata.xml", "rw");
	// if the metadata file exists
	if (fp) {

	}

	fclose(fp);

}

Metadata::~Metadata()
{
}


void Metadata::saveMetadata() {
	ptree root;

	ptree researcher;
	researcher.push_back(ptree::value_type("Name", ptree(ui.nameLineEdit->text().toStdString())));
	researcher.push_back(ptree::value_type("Email", ptree(ui.emailLineEdit->text().toStdString())));
	researcher.push_back(ptree::value_type("Phone", ptree(ui.phoneLineEdit->text().toStdString())));
	researcher.push_back(ptree::value_type("Website", ptree(ui.websiteLineEdit->text().toStdString())));

	root.push_back(ptree::value_type("Researcher", researcher));

	ptree intsitution;
	intsitution.push_back(ptree::value_type("Institution Name", ptree(ui.nameLineEdit_3->text().toStdString())));
	intsitution.push_back(ptree::value_type("Address", ptree(ui.addressLineEdit->text().toStdString())));
	intsitution.push_back(ptree::value_type("Department", ptree(ui.departmentLineEdit->text().toStdString())));

	root.push_back(ptree::value_type("Institution", intsitution));

	ptree project;
	project.push_back(ptree::value_type("Project Name", ptree(ui.projectNameLineEdit->text().toStdString())));
	project.push_back(ptree::value_type("Project URL", ptree(ui.projectURLLineEdit->text().toStdString())));
	project.push_back(ptree::value_type("Funding", ptree(ui.fundingAcknowledgementsLineEdit->text().toStdString())));
	project.push_back(ptree::value_type("Site Name", ptree(ui.siteNameLineEdit->text().toStdString())));
	project.push_back(ptree::value_type("Location", ptree(ui.locationLineEdit->text().toStdString())));
	project.push_back(ptree::value_type("Latitude", ptree(ui.latitudeLineEdit->text().toStdString())));
	project.push_back(ptree::value_type("Longitude", ptree(ui.longitudeLineEdit->text().toStdString())));
	project.push_back(ptree::value_type("Elevation", ptree(ui.elevationLineEdit->text().toStdString())));

	root.push_back(ptree::value_type("Project", project));

	std::stringstream output;
	boost::property_tree::xml_parser::write_xml(output, root);
}
