#ifndef TRACE_H
#define TRACE_H

// C\C++ standard library:
#include <string>
#include <vector>

// RsaToolbox:
#include "Definitions.h"
#include "InstrumentPropertyBaseClass.h"
#include "Vna.h"

namespace RsaToolbox {
	class Trace : public InstrumentPropertyBaseClass  {
	public:
		int port1;
		int port2;
		int channelNumber;
		int diagramNumber;
		TraceFormat format;

		// Property sync
		void Push(void);
		void Pull(void);

		// Status
		typedef vector<Trace>::iterator iterator;
		void UsedInChannels(vector<Channel *> &channels);
		void UsedInDiagrams(vector<Diagram *> &diagrams);

		// Operators
		bool operator==(Trace &otherTrace);

		// Actions
		void Read(std::vector<double> &data);
		void Read(std::vector<double> &data, std::vector<double> &frequency);
		void Delete(void);

		// Friends
		friend class Vna;

	private:
		Trace();
	};
}

#endif
