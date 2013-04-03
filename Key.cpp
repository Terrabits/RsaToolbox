
// RsaToolbox
#include "Key.h"
using namespace RsaToolbox;

// C++ Standard Library
#include <ios>
#include <fstream>
using namespace std;

// Constructor
Key::Key(string path) {
	if (*(path.end() - 1) != '\\')
		path = path + "\\";
	this->path = path;


}


// Get
bool Key::GetSetting(string key, bool &value) {
	AppendThisPath(key);
	ifstream keyfile(key, ios::in | ios::binary);
	keyfile.read( (char*) &value, sizeof(value));
	if (!keyfile) {
		keyfile.close();
		return(false); }
	else {
		keyfile.close();
		return(true); }


}
bool Key::GetSetting(string key, int &value) {
	AppendThisPath(key);
	ifstream keyfile(key, ios::in | ios::binary);
	keyfile.read( (char*) &value, sizeof(value));
	if (!keyfile) {
		keyfile.close();
		return(false); }
	else {
		keyfile.close();
		return(true); }


}
bool Key::GetSetting(string key, double &value) {
	AppendThisPath(key);
	ifstream keyfile(key, ios::in | ios::binary);
	keyfile.read( (char*) &value, sizeof(value));
	if (!keyfile) {
		keyfile.close();
		return(false); }
	else {
		keyfile.close();
		return(true); }


}
bool Key::GetSetting(string key, string &value) {
	AppendThisPath(key);
	ifstream keyfile(key);
	getline(keyfile, value);
	if (!keyfile) {
		keyfile.close();
		return(false); }
	else {
		keyfile.close();
		return(true); }


}

// Set
bool Key::SetSetting(string key, bool value) {
	AppendThisPath(key);
	ofstream keyfile(key, ios::out | ios::binary);
	keyfile.write( (char*) &value, sizeof(value));
	if (!keyfile) {
		keyfile.close();
		return(false); }
	else {
		keyfile.close();
		return(true); }


}
bool Key::SetSetting(string key, int value) {
	AppendThisPath(key);
	ofstream keyfile(key, ios::out | ios::binary);
	keyfile.write( (char*) &value, sizeof(value));
	if (!keyfile) {
		keyfile.close();
		return(false); }
	else {
		keyfile.close();
		return(true); }


}
bool Key::SetSetting(string key, double value) {
	AppendThisPath(key);
	ofstream keyfile(key, ios::out | ios::binary);
	keyfile.write( (char*) &value, sizeof(value));
	if (!keyfile) {
		keyfile.close();
		return(false); }
	else {
		keyfile.close();
		return(true); }


}
bool Key::SetSetting(string key, string value) {
	AppendThisPath(key);
	ofstream keyfile(key);
	keyfile << value << endl;
	if (!keyfile) {
		keyfile.close();
		return(false); }
	else {
		keyfile.close();
		return(true); }


}
bool Key::SetSetting(string key, char *value) {
	return( SetSetting(key, string(value)) );


}

// Helper
void Key::AppendThisPath(string &key) {
	key = path + key;


}


