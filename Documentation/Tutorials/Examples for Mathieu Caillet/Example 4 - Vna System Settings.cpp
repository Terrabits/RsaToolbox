
    //////////////////////////////////////
    //
    // Example #4: Vna System Settings
    //
    //////////////////////////////////////

    // Display settings
    bool isDisplayOn = vna.settings().isDisplayOn();
    vna.settings().isDisplayOff();
    vna.settings().displayOff();
    vna.settings().displayOn();

    // RF On/Off
    bool isRfOn = vna.settings().isRfOutputPowerOn();
    vna.settings().isRfOutputPowerOff();
    vna.settings().rfOutputPowerOff();
    vna.settings().rfOutputPowerOn();

    // Low Power autocal
    bool isLowPowerCal = vna.settings().isLowPowerAutoCalOn();
    vna.settings().isLowPowerAutoCalOff();
    vna.settings().lowPowerAutoCalOn();
    vna.settings().lowPowerAutoCalOff();

    // Dynamic IF Bandwidth
    bool isDynamicIfBw = vna.settings().isDynamicIfBandwidthOn();
    vna.settings().isDynamicIfBandwidthOff();
    vna.settings().dynamicIfBandwidthOff();
    vna.settings().dynamicIfBandwidthOn();

    // User Presets
    bool isUserPreset = vna.settings().isUserPresetOn();
    vna.settings().isUserPresetOff();
    vna.settings().setUserPreset("myPreset");
    QString userPreset = vna.settings().userPreset(); // "myPreset"
    vna.settings().userPresetOn();
    vna.settings().userPresetOff();

    // Map User Preset to *RST
    // (vna.preset()) command
    vna.settings().isUserPresetMappedToRst();
    vna.settings().mapUserPresetToRst(true); // On
    vna.settings().mapUserPresetToRst(false); // Off (default)

    // Emulation Mode
    vna.settings().isEmulationOn();
    vna.settings().isEmulationOff();
    vna.settings().isEmulationMode(HP_8720_EMULATION);
    vna.settings().setEmulationMode(HP_8720_EMULATION);
    vna.settings().setEmulationOff();