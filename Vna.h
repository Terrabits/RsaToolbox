#ifndef VNA_H
#define VNA_H

// C, C++ standard library:
#include <string>
#include <vector>

// RsaToolbox:
#include "Definitions.h"
#include "Log.h"
#include "IO.h"
#include "Trace.h"

namespace RsaToolbox {
	class Vna {
	public:
		std::string model;
		std::string firmwareVersion;
		std::string options;
		int numberOfPorts;
		//bool updateDisplay;
        Log log;
		IO io;
		/*InstrumentPropertyList<Channel> channels;
		InstrumentPropertyList<Diagram> diagrams;
		InstrumentPropertyList<Trace> traces;*/
		// Calibration?

		// Constructor / Destructor
        Vna(ConnectionType connectionType, QString address, QString log_directory, QString log_filename, QString program_name, QString version);
		~Vna();

		// Actions
		void Preset(void);
		void ClearStatus(void);
		std::vector<int> GetChannels(void);
		std::vector<double> GetDelays(int channel);
		int GetChannelOfTrace(std::string traceName);
		std::vector<int> GetDiagrams(void);
		std::vector<std::string> GetTracesInDiagram(int diagram);

		//// Sync functions
		//void Push(void);
		//void Pull(void);

		//friend class IO;
		//friend class InstrumentPropertyBaseClass;
		//template <class T> friend class InstrumentPropertyList;

	private:
		// Helpers
		int GetNumberOfPorts(void);
		bool ReadIndices(std::string line, std::vector<int> &indices);
		bool ReadNames(std::string line, std::vector<std::string> &names);
		/*Channel& NewChannel(void);
		Channel& NewChannel(int number);
		Channel& NewChannel(std::string name);

		Diagram& NewDiagram(void);
		Diagram& NewDiagram(int number);
		Diagram& NewDiagram(std::string name);

		Trace& NewTrace(void);
		Trace& NewTrace(int number);
		Trace& NewTrace(std::string name);

		void Delete(Channel &channel);
		void Delete(Diagram &diagram);
		void Delete(Trace &trace);*/
	};
}

#endif
