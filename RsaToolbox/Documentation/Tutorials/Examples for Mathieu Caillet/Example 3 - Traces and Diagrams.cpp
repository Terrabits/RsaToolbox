
    //////////////////////////////////////
    //
    // Example #3: Traces and Diagrams
    //
    //////////////////////////////////////

    // Delete all traces and diagrams
    vna.deleteTraces();
    vna.deleteDiagrams();

    // Create a trace in channel 1
    // Note: due to firmware limitations, no spaces
    // or math operators are allowed
    vna.createTrace("myFirstTrace", 1);
    vna.createTrace("myLastTrace", 1);

    // Retrieve existing traces
    // Should be: "myFirstTrace", "myLastTrace"
    QStringList traces = vna.traces();

    // Delete myLastTrace
    vna.deleteTrace("myLastTrace");

    // Set myFirstTrace to measure S21
    // Available parameter types:
    // - S_PARAMETER
    // - Y_PARAMETER
    // - Z_PARAMETER
    vna.trace("myFirstTrace").setNetworkParameter(S_PARAMETER, 2, 1);

    // Set the format of the trace.
    // Available formats are:
    // - DB_MAGNITUDE_TRACE
    // - PHASE_DEG_TRACE
    // - SMITH_CHART_TRACE
    // - POLAR_CHART_TRACE
    // - VSWR_TRACE
    // - UNWRAP_PHASE_DEG_TRACE
    // - LINEAR_MAGNITUDE_TRACE
    // - INVERSE_SMITH_CHART_TRACE
    // - REAL_PART_TRACE
    // - IMAGINARY_PART_TRACE
    // - DELAY_TRACE
    vna.trace("myFirstTrace").setFormat(LINEAR_MAGNITUDE_TRACE);

    // Display trace in a new diagram
    uint myDiagram = vna.createDiagram();
    vna.trace("myFirstTrace").setDiagram(myDiagram);

    // Autoscale the diagram
    vna.diagram(myDiagram).autoscale();

    // Other trace types are also available.
    // To measure an impedance:
    vna.createTrace("ZRe_S11", 1);
    vna.trace("ZRe_S11").setImpedance(1,1);

    // To measure waves:
    vna.createTrace("a1", 1);

    // To measure wave ratios:
    vna.createTrace("b1_over_a1", 1);
    vna.trace("b1_over_a1").setWaveRatio(B_WAVE, 1, A_WAVE, 1);

    // Get a list of available diagrams
    QVector<uint> diagrams = vna.diagrams();

    // Delete all diagrams and traces
    vna.deleteTraces();
    vna.deleteDiagrams();