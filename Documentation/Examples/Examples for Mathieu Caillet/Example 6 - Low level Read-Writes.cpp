
    //////////////////////////////////////
    //
    // Example #6: Low-level read/writes
    //
    //////////////////////////////////////

    vna.write("*RST");
    QString idString = vna.query("*IDN?");

    // The buffer size and timeout
    // can also be set. The buffer is
    // internal, so you do not have to
    // worry about manipulating it.
    // in this example:
    // buffer size: 60 Bytes
    // Time out: 100 ms
    idString = vna.query("*IDN?", 60, 100);

    // For SCPI commands that support
    // binary data transfers, there are
    // two functions depending on whether or
    // not you retrieve real or complex data.
    // These functions set up little endian,
    // 64 bit binary format automatically
    vna.queryVector("SCPI_COMMAND", _BUFFER_SIZE_, _TIMEOUT_);
    vna.queryComplexVector("SCPI_COMMAND", _BUFFER_SIZE_, _TIMEOUT_);

    // If you want to control the data
    // transfer format manually:
    vna.settings().setBigEndian();
    vna.settings().setLittleEndian();
    vna.settings().setRead32BitBinaryFormat();
    vna.settings().setRead64BitBinaryFormat();
    vna.settings().setReadAsciiFormat();

    // The transfer format can be queried:
    vna.settings().isReadAsciiFormat();
    vna.settings().isRead64BitBinaryFormat();