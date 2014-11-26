
    //////////////////////////////////////
    //
    // Example #2: Channels
    //
    //////////////////////////////////////

    vna.preset(); // *RST

    // Create specific channels
    vna.createChannel(2); // Creates channel 2
    vna.createChannel(3); // Creates channel 3

    // Create next channel (4)
    uint myChannel = vna.createChannel();

    // Delete a channel
    vna.deleteChannel(myChannel);

    // You can delete all channels with the function:
    vna.deleteChannels();
    // Note: Because of firmware limitations, channel 1
    // will still exist.

    // Get a list of all channels
    // Result: 1
    QVector<uint> channels = vna.channels();

    // Sweep channel manually
    vna.channel(1).manualSweepOn();
    vna.channel(1).startSweep();

    // Place channel back into continuous sweep
    // Note: channel() menu defaults to 1
    vna.channel().continuousSweepOn();

    // Set channel sweep type.
    // Values include:
    // - LINEAR_SWEEP
    // - LOG_SWEEP
    // - SEGMENTED_SWEEP
    // - POWER_SWEEP
    // - CW_SWEEP
    // - TIME_SWEEP
    vna.channel().setSweepType(LINEAR_SWEEP);

    // Common values for each sweep type are
    // grouped into a submenu
    vna.channel().linearSweep().setStart(1, GIGA_PREFIX);
    vna.channel().linearSweep().setStop(2, GIGA_PREFIX);
    vna.channel().linearSweep().setIfbandwidth(1, KILO_PREFIX);

    // Values can be retrieved.
    // For example:
    double startFreq_Hz = vna.channel().linearSweep().start_Hz(); // Units: Hz

    // Averaging is set per channel:
    vna.channel().averaging().setNumber(5);
    uint averages = vna.channel().averaging().number();
    bool isAveragingOn = vna.channel().averaging().isOn();
    vna.channel().averaging().on();
    vna.channel().averaging().off();

    // Measure S-Parameters for ports 1, 2
    NetworkData data = vna.channel().linearSweep().measure(1, 2);

    // NetworkData holds results of an N-port measurement
    bool isSParameter = data.isSParameter();
    uint points = data.points();
    uint numberOfPorts = data.numberOfPorts();
    QRowVector frequencies_Hz = data.x();
    ComplexMatrix3D s = data.y(); // All the data

    // NetworkData also provides convenience
    // functions to retrieve values of interest.
    // Consider the following function calls that
    // return the values of a particular "trace" of
    // data:
    QRowVector s11_dB = data.y_dB(1,1);
    QRowVector s21_deg = data.y_phase_deg(2,1);
    QRowVector s22_real = data.y_real(2,2);

    // Note that the statement:
    // s11_dB.size() == points
    // is true (s11_dB is vs Frequency)

    // Note also that if you want to process data manually,
    // y() returns a 3D matrix organized
    // with indices:
    // s[POINT-1][OUTPUT_PORT-1][INPUT_PORT-1]
    // For example:
    ComplexDouble s11_firstPoint = s[0][1][1];
    ComplexDouble s12_firstPoint = s[0][0][1];
    ComplexDouble s21_firstPoint = s[0][1][0];
    ComplexDouble s22_firstPoint = s[0][1][1];
    ComplexDouble s21_lastPoint  = s[points-1][1][0];

    // Save s2p file for ports 1, 2
    // Extension is added automatically to filename
    // Default format is Real, Imag
    vna.channel().linearSweep().saveSnp("C:\\Small Network", 1, 2);

    // For a larger or arbitrary number of ports,
    // the list of ports can be a variable
    QVector<uint> ports;
    ports << 1 << 2 << 3 << 4;
    vna.channel().linearSweep().saveSnp("C:\\Larger Network", ports);