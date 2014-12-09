
    //////////////////////////////////////
    //
    // Example #0: Connect to VNA
    //
    //////////////////////////////////////

    // Create a log file
    QString logPath = "C:\\";
    QString logFilename = "Examples for Mathieu Log.txt";
    QString appName = "Examples for Mathieu";
    QString appVersion = "1.0.0";
    Log log(logPath, logFilename, appName, appVersion);

    // Print a header in the log file
    log.printApplicationHeader();

    // Connect to the Vna
    // ConnectionType values include:
    // - TCPIP_CONNECTION
    // - GPIB_CONNECTION
    // - USB_CONNECTION
    ConnectionType connectionType = TCPIP_CONNECTION;
    QString address = "127.0.0.1";
    Vna vna(connectionType, address);

    // Connect the Vna to the log file
    // Print instrument info to log
    vna.useLog(&log);
    vna.printInfo();

    // Exit if not a VNA connection.
    if (vna.isConnected() == false)
        return(0);

    // Exit if not Rohde & Schwarz instrument
    if (vna.isRohdeSchwarz() == false)
        return(0);

    // Exit if not a known R&S Vna
    if (vna.properties().isUnknownModel())
        return(0);