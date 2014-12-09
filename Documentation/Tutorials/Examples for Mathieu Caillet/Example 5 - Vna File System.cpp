
    //////////////////////////////////////
    //
    // Example #5: Vna File System
    //
    //////////////////////////////////////

    // Get the current directory of the Vna
    // firmware
    vna.fileSystem().directory();

    // Change to an arbitrary directory
    vna.fileSystem().changeDirectory("Traces");

    // Change to a the predefined Cal Kit directory
    // VnaDirectory values include:
    // - DEFAULT_DIRECTORY
    // - EMBED_DIRECTORY
    // - DEEMBED_DIRECTORY
    // - CAL_GROUP_DIRECTORY
    // - CAL_KIT_DIRECTORY
    // - EXTERNAL_TOOLS_DIRECTORY
    // - RECALL_SETS_DIRECTORY
    // - TRACES_DIRECTORY
    vna.fileSystem().changeDirectory(CAL_KIT_DIRECTORY);
    QString calkitDir = vna.fileSystem().directory();

    // Change back to default
    vna.fileSystem().changeDirectory(DEFAULT_DIRECTORY);

    // Get a list of files in the current directory
    QStringList files = vna.fileSystem().files();

    // Get a list of directories in the current directory
    QStringList directories = vna.fileSystem().directories();

    // Transfer a file to the Vna:
    vna.fileSystem().uploadFile("SOURCE_PATH", "DESTINATION_PATH");

    // Transfer a file to a predefined location on the Vna:
    // For example, uploading a Cal kit:
    vna.fileSystem().uploadFile("C:\\...\\my.calkit", "my.calkit", CAL_KIT_DIRECTORY);

    // Test for existence.
    // If path is not included,
    // current directory is searched
    vna.fileSystem().isFile("FILE_NAME");
    vna.fileSystem().isDirectory("DIRECTORY_NAME");

    // Download a file from the Vna
    vna.fileSystem().downloadFile("SOURCE_FILE_PATH_NAME", "DESTINATION_FILE_PATH_NAME");

    // Download a file from a predefined location
    // For example, downloading a recall set
    vna.fileSystem().downloadFile("recall_file.znx", RECALL_SETS_DIRECTORY, "DESTINATION_PATH\\recall_file.znx");
