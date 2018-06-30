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
	ptree pt;
	try {
		boost::property_tree::xml_parser::read_xml("C:/Users/hmunoz/Documents/Visual Studio 2015/Projects/Thesis/GUI/Resources/userMetadata.xml", pt, boost::property_tree::xml_parser::trim_whitespace);
		ui.nameLineEdit->setText(QString::fromStdString(pt.get("Researcher.Name", "")));
		ui.nameLineEdit->setText(QString::fromStdString(pt.get("Researcher.Email", "")));
		ui.nameLineEdit->setText(QString::fromStdString(pt.get("Researcher.Phone", "")));
		ui.nameLineEdit->setText(QString::fromStdString(pt.get("Researcher.Website", "")));

		ui.nameLineEdit->setText(QString::fromStdString(pt.get("Institution.InstitutionName", "")));
		ui.nameLineEdit->setText(QString::fromStdString(pt.get("Institution.Adress", "")));
		ui.nameLineEdit->setText(QString::fromStdString(pt.get("Institution.Department", "")));

		ui.nameLineEdit->setText(QString::fromStdString(pt.get("Project.ProjectName", "")));
		ui.nameLineEdit->setText(QString::fromStdString(pt.get("Project.ProjectURL", "")));
		ui.nameLineEdit->setText(QString::fromStdString(pt.get("Project.Funding", "")));
		ui.nameLineEdit->setText(QString::fromStdString(pt.get("Project.SiteName", "")));
		ui.nameLineEdit->setText(QString::fromStdString(pt.get("Project.Location", "")));
		ui.nameLineEdit->setText(QString::fromStdString(pt.get("Project.Latitude", "")));
		ui.nameLineEdit->setText(QString::fromStdString(pt.get("Project.Longitude", "")));
		ui.nameLineEdit->setText(QString::fromStdString(pt.get("Project.Elevation", "")));
	}
	catch (const boost::property_tree::xml_parser::xml_parser_error& ex){

	}
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
	intsitution.push_back(ptree::value_type("InstitutionName", ptree(ui.nameLineEdit_3->text().toStdString())));
	intsitution.push_back(ptree::value_type("Address", ptree(ui.addressLineEdit->text().toStdString())));
	intsitution.push_back(ptree::value_type("Department", ptree(ui.departmentLineEdit->text().toStdString())));

	root.push_back(ptree::value_type("Institution", intsitution));

	ptree project;
	project.push_back(ptree::value_type("ProjectName", ptree(ui.projectNameLineEdit->text().toStdString())));
	project.push_back(ptree::value_type("ProjectURL", ptree(ui.projectURLLineEdit->text().toStdString())));
	project.push_back(ptree::value_type("Funding", ptree(ui.fundingAcknowledgementsLineEdit->text().toStdString())));
	project.push_back(ptree::value_type("SiteName", ptree(ui.siteNameLineEdit->text().toStdString())));
	project.push_back(ptree::value_type("Location", ptree(ui.locationLineEdit->text().toStdString())));
	project.push_back(ptree::value_type("Latitude", ptree(ui.latitudeLineEdit->text().toStdString())));
	project.push_back(ptree::value_type("Longitude", ptree(ui.longitudeLineEdit->text().toStdString())));
	project.push_back(ptree::value_type("Elevation", ptree(ui.elevationLineEdit->text().toStdString())));

	root.push_back(ptree::value_type("Project", project));

	boost::property_tree::xml_parser::write_xml("C:/Users/hmunoz/Documents/Visual Studio 2015/Projects/Thesis/GUI/Resources/userMetadata.xml", root, std::locale(), boost::property_tree::xml_writer_settings<std::string>('\t', 1));

	this->close();
}
