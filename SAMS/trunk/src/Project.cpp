/**
 * @file Project.cpp
 * @brief Project Definition
 * @author Kurt Andrews & Brian Royer
 */

#include "Project.h"
#include "ProjectList.h"

using namespace std;

Project::Project(const string& _projectId,
					 const string& _desc) {
	setProjectId(_projectId);
	setDesc(_desc);
	
	clearAllPrograms();
}

Project::~Project() {
	clearAllPrograms();
}

void Project::addProgram(ProgramList* programs) {
	system("cls");
	cout << "Adding Program" << endl;
		
	Program* pPtr = programs->selectProgram();
		
	if (pPtr != NULL) {
			
		if (pPtr->getProject() == NULL) {
			pPtr->setProject((Project*) this);
			supportingPrograms.push_back(pPtr);
		} else {
			cout << "This program is already a part of the project" << endl;
			cin.ignore();
		}
	} else {
		cout << "\n\nNo programs were selected" << endl;
		cin.ignore();
	}
}

void Project::clearAttributes() {
	setProjectId("");
	setDesc("");
	
	clearAllPrograms();
}

void Project::clearAllPrograms() {
	for (int i = 0; i < supportingPrograms.size(); i++) {
		supportingPrograms[i]->setProject(NULL);
	}
	
	supportingPrograms.clear();
}

void Project::_display() const {
	cout << "Project ID:\t" << getProjectId() << endl;
	cout << "Description:\t" << getDesc() << endl << endl;
}

void Project::display() const {
	_display();
	
	cout << "*** P R O G R A M  S U P P O R T  L I S T***" << endl << endl;
	
	for (int i = 0; i < supportingPrograms.size(); i++) {
		cout << supportingPrograms[i]->getId()  << " - " << supportingPrograms[i]->getName() << endl;
	}
}

void Project::populate() {
	string _projectId;
	string _desc;
	
	if (getProjectId() == "") {
		cout << "Enter the project id: ";
		getline(cin, _projectId);
		
		setProjectId(_projectId);
	}
	
	cout << "Enter the project description: ";
	getline(cin, _desc);
	
	setDesc(_desc);
}

void Project::removeProgram() {
	if(supportingPrograms.size() > 0)
	{
		unsigned long i = 0;
	
		char option = 'N';
		while (option != 'Q') {
			system("cls");
			cout << "Remove Program" << endl << endl;
			_display();
			cout << supportingPrograms[i]->getName() << endl << endl;
			cout << "** (F)irst * (L)ast * (P)revious * (N)ext * (R)emove * (Q)uit ** ";
		
			cin >> option;
			cin.ignore();
		
			switch(toupper(option)) {
				case 'R':
					supportingPrograms[i]->setProject(NULL);
					supportingPrograms.erase(supportingPrograms.begin() + i); // remove the program from the project
					option = 'Q';
					break;
				case 'F': i = 0;
					break;
				case 'L':i = supportingPrograms.size() - 1;
					break;
				case 'P':
					if (i == 0) {
						i = supportingPrograms.size() - 1;
					} else {
						-- i;
					}
					break;
				case 'N':
					++ i;
				
					if (i == supportingPrograms.size()) {
						i = 0;
					}
					break;
				case 'Q': option = 'Q'; break;
			}
		}
	}
	else
	{
		cout << "This project is not supporting any programs." << endl << endl;
		cin.ignore();
	}
}

void Project::removeDeletedProgram(Program* program)
{	
	supportingPrograms.erase(std::remove(supportingPrograms.begin(), supportingPrograms.end(), program), supportingPrograms.end());
}

void Project::startup(ifstream& inFile, ProgramList* programs) {
	string _projectId;
	getline(inFile, _projectId, '|');
	setProjectId(_projectId);
	
	string _desc;
	getline(inFile, _desc);
	setDesc(_desc);
	
	int recs;
	string _programId;
	Program* program = NULL;
	
	inFile >> recs;
	inFile.ignore();
	
	for (int rec = 0; rec < recs; ++rec) {
		inFile >> _programId;
		program = programs->find(_programId);
		
		if (program != NULL) {
			program->setProject((Project*) this);
			supportingPrograms.push_back(program);
		}
	}
}

void Project::shutdown(ofstream& outFile)
{
	outFile << getProjectId() << '|'
					<< getDesc() << endl;
	
	outFile << supportingPrograms.size() << endl;
	
	for (long int rec = 0; rec < supportingPrograms.size(); rec++) {
		outFile << supportingPrograms[rec]->getId() << endl;
	}
}