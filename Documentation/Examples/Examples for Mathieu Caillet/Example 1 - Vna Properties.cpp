
    //////////////////////////////////////
    //
    // Example #1: VNA Properties
    //
    //////////////////////////////////////


    // Check for a particular VNA model
    bool isZnb = vna.properties().isZnbFamily();
    bool isNotZva = vna.properties().isNotZvaFamily();

    // Retrieve instrument model.
    // Return value is of type VnaModel
    // Values include:
    // - ZVA_MODEL
    // - ZVB_MODEL
    // - ZVH_MODEL
    // - ZVL_MODEL
    // - ZVT_MODEL
    // - ZNB_MODEL
    // - ZNBT_MODEL
    // - ZNC_MODEL
    // - ZNP_MODEL
    // - UNKNOWN_MODEL
    // (UNKNOWN_MODEL means not a R&S VNA)
    VnaModel model = vna.properties().model();

    // Get firmware version
    QString firmware = vna.properties().firmwareVersion();

    // Test for an option
    bool isK0 = vna.properties().optionsList().contains("K0", Qt::CaseInsensitive);

    // Get number of ports on Vna
    // (Does not include switch matrix)
    uint physicalPorts = vna.properties().physicalPorts();
    
    // Get number of test ports,
    // including switch matrix ports
    uint testPorts = vna.testPorts();

    // Get max, min measurement values
    double maxFrequency_Hz = vna.properties().maximumFrequency_Hz();
    vna.properties().minimumFrequency_Hz();
    vna.properties().maximumPower_dBm();
    vna.properties().minimumPower_dBm();
    vna.properties().maximumPoints();

    // Check for IF BW values
    // These are returned in groups by their
    // SI Prefix, which is convenient for
    // drop-down menus
    QRowVector ifValues_Hz = vna.properties().ifBandwidthMantissa_Hz();
    vna.properties().ifBandwidthMantissa_KHz();
    vna.properties().ifBandwidthMantissa_MHz();

    // Check for internal attenuators
    bool isRxAttenuators = vna.properties().hasReceiverAttenuators();
    QVector<uint> rxAttenuations_dB = vna.properties().receiverAttenuations_dB();
    vna.properties().hasSourceAttenuators();
    vna.properties().receiverAttenuations_dB();