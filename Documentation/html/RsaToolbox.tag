<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile>
  <compound kind="file">
    <name>GenericBus.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Bus/</path>
    <filename>_generic_bus_8cpp</filename>
    <includes id="_generic_bus_8h" name="GenericBus.h" local="yes" imported="no">GenericBus.h</includes>
  </compound>
  <compound kind="file">
    <name>GenericBus.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Bus/</path>
    <filename>_generic_bus_8h</filename>
    <class kind="class">RsaToolbox::GenericBus</class>
    <namespace>RsaToolbox</namespace>
    <member kind="enumeration">
      <type></type>
      <name>ConnectionType</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa1f0e2efd52935fd01bfece0fbead81f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>TCPIP_CONNECTION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa1f0e2efd52935fd01bfece0fbead81fa14c1f2316495d5cd32f37c7423fce72c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>GPIB_CONNECTION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa1f0e2efd52935fd01bfece0fbead81fa0fa118c77d3b0455c890e59388c6e347</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>USB_CONNECTION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa1f0e2efd52935fd01bfece0fbead81fa5d196bbeccdb8265b1082c35c3ee7b9f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>NO_CONNECTION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa1f0e2efd52935fd01bfece0fbead81facad28945d500e3fc972e2d1c3b948e8e</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>acc3af340369d563a1bb92e769ebedc86</anchor>
      <arglist>(ConnectionType connection_type)</arglist>
    </member>
    <member kind="function">
      <type>ConnectionType</type>
      <name>toConnectionType</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aedec38fe38dd15d5baf70ec815e3ccf1</anchor>
      <arglist>(QString scpi)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>rsib.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Bus/Rsib/</path>
    <filename>rsib_8h</filename>
    <member kind="define">
      <type>#define</type>
      <name>IBSTA_ERR</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>aed118b948a7b870ef76052646f6a3af8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IBSTA_TIMO</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>ad3281e4a7eafff9a32b676eb0ceb50f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IBSTA_CMPL</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>a98f1810ce547f9184d86399f3868eb49</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IBSTA_REM</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>acc183282a6e3f373bb9c4a23586eca7e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IBERR_DEVICE_REGISTER</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>a40fa2533b795113bc9394019c66b7b0c</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IBERR_CONNECT</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>af9ff7d2f69a755bde579b4d382e20896</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IBERR_NO_DEVICE</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>a2a8b3989f4eb37bcefa6c0e3c753b28e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IBERR_MEM</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>a9c9c49475f2fd916c19cabf85192477f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IBERR_TIMEOUT</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>a33ada914bef4bbc8e032ba27b1b72853</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IBERR_BUSY</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>a37b73f1549978e94ee0568235792da61</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IBERR_FILE</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>ad1b2d59b612b3c7d57b6abaf9d735bae</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IBERR_UNKNOWN</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>a246b01914ed0cfc0e886dddb1f556cce</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>short WINAPI</type>
      <name>RSDLLibfind</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>ab3026911ceb2c264c398a115043fa399</anchor>
      <arglist>(char far *szName, short far *ibsta, short far *iberr, unsigned long far *ibcntl)</arglist>
    </member>
    <member kind="function">
      <type>short WINAPI</type>
      <name>RSDLLibwrt</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>a3ab0548a2ba609e6926f90c9e64dcdd5</anchor>
      <arglist>(short ud, char far *szWrt, short far *ibsta, short far *iberr, unsigned long far *ibcntl)</arglist>
    </member>
    <member kind="function">
      <type>short WINAPI</type>
      <name>RSDLLilwrt</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>a906cdff08be42ed4162406ec4ad8fffd</anchor>
      <arglist>(short ud, char far *pcWrt, unsigned long ulCnt, short far *ibsta, short far *iberr, unsigned long far *ibcntl)</arglist>
    </member>
    <member kind="function">
      <type>short WINAPI</type>
      <name>RSDLLibwrtf</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>aea62b460cc242523700909229d2fa0f2</anchor>
      <arglist>(short ud, char far *szFileName, short far *ibsta, short far *iberr, unsigned long far *ibcntl)</arglist>
    </member>
    <member kind="function">
      <type>short WINAPI</type>
      <name>RSDLLibrd</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>abc76062f9e87cd59ba50de448aa4262c</anchor>
      <arglist>(short ud, char far *pcRd, short far *ibsta, short far *iberr, unsigned long far *ibcntl)</arglist>
    </member>
    <member kind="function">
      <type>short WINAPI</type>
      <name>RSDLLilrd</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>a8949221c0d3a67e67447919721d0582f</anchor>
      <arglist>(short ud, char far *pcRd, unsigned long ulCnt, short far *ibsta, short far *iberr, unsigned long far *ibcntl)</arglist>
    </member>
    <member kind="function">
      <type>short WINAPI</type>
      <name>RSDLLibrdf</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>a0254ab5d8cace057646914703aeb6166</anchor>
      <arglist>(short ud, char far *szFileName, short far *ibsta, short far *iberr, unsigned long far *ibcntl)</arglist>
    </member>
    <member kind="function">
      <type>void WINAPI</type>
      <name>RSDLLTestSrq</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>a7183eeaed9fe773a7e329eaf0ac5d039</anchor>
      <arglist>(short ud, short far *result, short far *ibsta, short far *iberr, unsigned long far *ibcntl)</arglist>
    </member>
    <member kind="function">
      <type>void WINAPI</type>
      <name>RSDLLWaitSrq</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>a8cb65f60b2f927b8f015acf8954de924</anchor>
      <arglist>(short ud, short far *result, short far *ibsta, short far *iberr, unsigned long far *ibcntl)</arglist>
    </member>
    <member kind="function">
      <type>short WINAPI</type>
      <name>RSDLLibrsp</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>af6af2f7cf45c0b87bd301c3d34ea37dc</anchor>
      <arglist>(short ud, char far *spr, short far *ibsta, short far *iberr, unsigned long far *ibcntl)</arglist>
    </member>
    <member kind="function">
      <type>void WINAPI</type>
      <name>RSDLLibtmo</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>a33c617f6f637f4089dd774016906022e</anchor>
      <arglist>(short ud, short tmo, short far *ibsta, short far *iberr, unsigned long far *ibcntl)</arglist>
    </member>
    <member kind="function">
      <type>void WINAPI</type>
      <name>RSDLLibsre</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>adc90afaa05063c7d2a38b26c149ab69f</anchor>
      <arglist>(short ud, short v, short far *ibsta, short far *iberr, unsigned long far *ibcntl)</arglist>
    </member>
    <member kind="function">
      <type>short WINAPI</type>
      <name>RSDLLibclr</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>a060ecd7e6b1be72fc5d7a367fc2c0e5a</anchor>
      <arglist>(short ud, short *ibsta, short *iberr, unsigned long *ibcntl)</arglist>
    </member>
    <member kind="function">
      <type>void WINAPI</type>
      <name>RSDLLibloc</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>a6a46710101f8226909e96704df9cfb92</anchor>
      <arglist>(short ud, short far *ibsta, short far *iberr, unsigned long far *ibcntl)</arglist>
    </member>
    <member kind="function">
      <type>void WINAPI</type>
      <name>RSDLLibeot</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>a395877e79d1397c40dbb09c7405b212d</anchor>
      <arglist>(short ud, short v, short far *ibsta, short far *iberr, unsigned long far *ibcntl)</arglist>
    </member>
    <member kind="function">
      <type>void WINAPI</type>
      <name>RSDLLibonl</name>
      <anchorfile>rsib_8h.html</anchorfile>
      <anchor>ac259e2bb78fb71a2a5972f3ccfdf42ba</anchor>
      <arglist>(short ud, short v, short far *ibsta, short far *iberr, unsigned long far *ibcntl)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>RsibBus.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Bus/Rsib/</path>
    <filename>_rsib_bus_8cpp</filename>
    <includes id="_rsib_bus_8h" name="RsibBus.h" local="yes" imported="no">RsibBus.h</includes>
    <includes id="rsib_8h" name="rsib.h" local="yes" imported="no">rsib.h</includes>
  </compound>
  <compound kind="file">
    <name>RsibBus.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Bus/Rsib/</path>
    <filename>_rsib_bus_8h</filename>
    <includes id="_generic_bus_8h" name="GenericBus.h" local="yes" imported="no">GenericBus.h</includes>
    <class kind="class">RsaToolbox::RsibBus</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>visa.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Bus/Visa/</path>
    <filename>visa_8h</filename>
    <includes id="visatype_8h" name="visatype.h" local="yes" imported="no">visatype.h</includes>
    <member kind="define">
      <type>#define</type>
      <name>VI_SPEC_VERSION</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a831503816d4136722a05e3162c779b03</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_RSRC_CLASS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a10b659d698d4bf87ee65b4923681b649</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_RSRC_NAME</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a73cf017400f5ed396bd0165f547fcaa6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_RSRC_IMPL_VERSION</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab34a390ebd96490a754119e096eaf693</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_RSRC_LOCK_STATE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>affa02d0d5eb5e211311856dfd2932953</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_MAX_QUEUE_LENGTH</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a8d7222c7d5ae297d0ef6b8661c414f5e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_USER_DATA_32</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa17658e1914fa536289db7ab9369034a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_FDC_CHNL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a41be00386851b38d56cab8d1b828193a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_FDC_MODE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a568b36a230af05c602c9ca640da9e8b8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_FDC_GEN_SIGNAL_EN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a1e47b2b7913b8f83b32946db4ab57ceb</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_FDC_USE_PAIR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab27d96d50bc615af5c76d315367951ea</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_SEND_END_EN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a0821ad630f3fac788d5209eb0b375d93</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_TERMCHAR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a20dbb82d288d587522c5a3c874eb0f6b</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_TMO_VALUE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a5d2971bb43f910a2e45e4cedd7509f63</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_GPIB_READDR_EN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a573160454b4e943f63b60b5330102044</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_IO_PROT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a719d4002e580ae14d28a3633bbf104d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_DMA_ALLOW_EN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab2bd03564a338224529280a8e7d1c311</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_ASRL_BAUD</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a78999f5696149c69599256f0ab9fc53a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_ASRL_DATA_BITS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a2a8c3097cf63332a43f184432500516b</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_ASRL_PARITY</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a0322f140c9e502d0ef1cc1c9ef94bfe3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_ASRL_STOP_BITS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a883d73e0a7d36ceaffb7bd9677ffe426</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_ASRL_FLOW_CNTRL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac9ce114e5494daf857d49a0b43f1cabf</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_RD_BUF_OPER_MODE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a9861b0810f8259e70016096c7ebcfb62</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_RD_BUF_SIZE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aef07a7d0ff9a5b789c1ddd46371895d5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_WR_BUF_OPER_MODE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a9e092ac08f04ea76e123b124d8b1d050</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_WR_BUF_SIZE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a77b2b9b10393dd1fed9a1612ca49a050</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_SUPPRESS_END_EN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>af417e5b66bb9e33a6388faa51a6eb8a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_TERMCHAR_EN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a6b25c34bb76948f25773482c6be0e3be</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_DEST_ACCESS_PRIV</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a2d0bfd11d5b09f124335abf27b4f060c</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_DEST_BYTE_ORDER</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a35e9c2752faf6f1b585fe38c87f7b80f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_SRC_ACCESS_PRIV</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a297087aad7a159a8fc000a70c304af20</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_SRC_BYTE_ORDER</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>af341463d56b9245ba29870cba5ae47c2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_SRC_INCREMENT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad47c126c882bbc65bccbcf7d6ebedf9e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_DEST_INCREMENT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab39983046af5acb5c1fa70d565c68877</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_WIN_ACCESS_PRIV</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ae3c7bdcedfe4c8d4cae4a0ef010f3e0e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_WIN_BYTE_ORDER</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a9f79873ef5d9c8f5d48d21cd8e6c15a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_GPIB_ATN_STATE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a6f89373fc96d82ca68f526efda0e60ef</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_GPIB_ADDR_STATE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ae2731abdf58cc421661b8bf3cc2fbf97</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_GPIB_CIC_STATE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>acc41f804a99500e724ff11a613747693</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_GPIB_NDAC_STATE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac6257474e5a02d3d89a2d1ae408c4bd3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_GPIB_SRQ_STATE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a6e23658ec7ff75a45dfe73c210df53bc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_GPIB_SYS_CNTRL_STATE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a1f3ae58301d2c75d9580edeb07bb8aa9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_GPIB_HS488_CBL_LEN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a820503d09fc495060649cb3fb4c4343f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_CMDR_LA</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a19f536d70a02ebb29ac12f17aafbb64d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_VXI_DEV_CLASS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad63a72cec35c96c4108fdcf89dcceb09</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_MAINFRAME_LA</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a8abb369a9a1da07206dd6b6ff6a4297d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_MANF_NAME</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a72bbeca2db0ceb772aca7b81331a0a82</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_MODEL_NAME</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a24711a363c331061bb7c6e4f8723feb8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_VXI_VME_INTR_STATUS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a86be293bca87b227663edfd61bcf3a89</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_VXI_TRIG_STATUS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a455a9d1a6b7db84e80ff0b8c846a2f36</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_VXI_VME_SYSFAIL_STATE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a0bcae715cf397eba960df1e4eeb949f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_WIN_BASE_ADDR_32</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a11bea1d37c2bb411b99f548d12b81d3b</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_WIN_SIZE_32</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad9fe65471404eb338631b6386dea8626</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_ASRL_AVAIL_NUM</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac897cd5d193e205d5f24100eeace9429</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_MEM_BASE_32</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a44496dc3c8f07b7254594ac50af15dfc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_ASRL_CTS_STATE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a8da84a9d83a18246f179ec532ff27bc3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_ASRL_DCD_STATE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a0275b9635a98c52ab4d9bf2e976f98c7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_ASRL_DSR_STATE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aff4d7444bba8602bd05604e043564efe</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_ASRL_DTR_STATE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad21647d9798b30bf0d12c4537bebb55f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_ASRL_END_IN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a1638d8ce1a33a12de03be6ec9cebd113</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_ASRL_END_OUT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a5b37cf80093a5adda34d826fd64cad00</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_ASRL_REPLACE_CHAR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a2cd8cf99850dabf9aaa75a305779af74</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_ASRL_RI_STATE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a3c88dadfa06d911bf21d3b013621851a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_ASRL_RTS_STATE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a8851e92c8a1e70f1917e5a118f4ad5fb</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_ASRL_XON_CHAR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a524c4bbe633bf7274cc6691051aa0a3c</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_ASRL_XOFF_CHAR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a9e82d927c3581b4e4693c79eba7f6cad</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_WIN_ACCESS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a42d01ce3c5b9dc69f890a32b6a825134</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_RM_SESSION</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad93a7e2295364045a4944c4997bf8969</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_VXI_LA</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad290634abd693aaee49c13277ae33175</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_MANF_ID</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a834628c210e82f47350b467f34cf77a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_MEM_SIZE_32</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a001d43d80f0d5a3464d2fe8a3ada3c21</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_MEM_SPACE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a779c80cb655c432dc15e8c0cfd79e162</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_MODEL_CODE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab5a90b7dd24b2f2eeca70dcc914b8c92</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_SLOT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a46d310c24d1df4a0c28e544a236d5a71</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_INTF_INST_NAME</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>af3ab3e7fddb08975f3588c6164a4b79a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_IMMEDIATE_SERV</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a380d42ffb015a7dcd9554084b782cd35</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_INTF_PARENT_NUM</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ae3c00fe91c8452aa84de895b679a72aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_RSRC_SPEC_VERSION</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a137329b93e8d69696e76ce3cc046d92e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_INTF_TYPE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a7fe16f57129ef25e65c041b5c54ee183</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_GPIB_PRIMARY_ADDR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>acd7dbed2df6b69173e83e3673167d5e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_GPIB_SECONDARY_ADDR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a984f685619a015d4cd074060e71589ab</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_RSRC_MANF_NAME</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa55ede6178eebdb99595b1431f8f75ee</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_RSRC_MANF_ID</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>af66f835ec242314b8a8d6899921f444b</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_INTF_NUM</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a281474df7f8ed95dddd84cf54b493c38</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_TRIG_ID</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a24453b4a91090bc303c6b4489969e58a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_GPIB_REN_STATE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a389f60fb69d523a71c61f0e5acf5b4a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_GPIB_UNADDR_EN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a2440560b84085a11cd2175513690eaf0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_DEV_STATUS_BYTE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>afe37e67c63ee846926b08244a8f0a031</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_FILE_APPEND_EN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a000714a71f3ae7e3c9364ac16e1d84d4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_VXI_TRIG_SUPPORT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a0ef1231e92438e3fe70f160870969c55</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_TCPIP_ADDR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a5c2d127404dde3574c4702cd4c886169</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_TCPIP_HOSTNAME</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>add019df58a6dd78b0df9466723504db0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_TCPIP_PORT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a53cbecfe4c8c7f8e196e3c1684e83ef8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_TCPIP_DEVICE_NAME</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa307138a62bcb3a974a95eb57bb1b9f1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_TCPIP_NODELAY</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>af2f07b11a1aea74efdd0bf38307c50b2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_TCPIP_KEEPALIVE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a0ad077253b11aa9527e45a7e8a1932a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_4882_COMPLIANT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a7ff446e4fe6d421d0eedeb3521e1a22e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_USB_SERIAL_NUM</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a7b51d888b0da5d73db903910ce07f6dd</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_USB_INTFC_NUM</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aed759293c9dca31c743548e841c321c4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_USB_PROTOCOL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a1fa72773e3cac99e02ccc7eff8f77ae5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_USB_MAX_INTR_SIZE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a61391db4f13ea9d76042bba8def3d8b2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_DEV_NUM</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a4b8e06d490ff6230d5775883a3636981</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_FUNC_NUM</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>afe4bf0a237eb112ca22e8fe2e1ae4811</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_BUS_NUM</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>abe0b6d8463e93bfed54c8b093a6acbe9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_CHASSIS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab157ba883b77d39b736ededcfa00b0db</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_SLOTPATH</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a028eb77e190076128cafa8dc3d0d9644</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_SLOT_LBUS_LEFT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aaed2abebb4212050bcc60f1a520786e2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_SLOT_LBUS_RIGHT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a131f344a811cf0d381dffead0219c713</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_TRIG_BUS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a74f1ef01c9396b4cf2e1f71f1e797ce9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_STAR_TRIG_BUS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa873bfff8961ceb6ce1bdb76c12079b9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_STAR_TRIG_LINE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>af621ee49d86940f1b0a4d860184e3d7f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_MEM_TYPE_BAR0</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad1b77d5b0fa05ed81cd0bae142a96494</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_MEM_TYPE_BAR1</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a00e5fac36ac59b853af19318e3d217db</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_MEM_TYPE_BAR2</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a4bb1619c6798622fbdc640027cc5597d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_MEM_TYPE_BAR3</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a70fe00f578929c756422393ebf7eb722</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_MEM_TYPE_BAR4</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>af432d71feaaa521c8e6f810c681736ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_MEM_TYPE_BAR5</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a7ec84ba5bfb91c0af39facd44bf6270f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_MEM_BASE_BAR0</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a74d7723587c9cbad01e77f131db44880</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_MEM_BASE_BAR1</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad417ae3c344b5d2bb225b07f7863bb4b</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_MEM_BASE_BAR2</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>afd61aeb943e19686db824ee954be71a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_MEM_BASE_BAR3</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>abc293430ceeeff630e8dbf816ac4b203</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_MEM_BASE_BAR4</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>af289b78a0ec7af6900ae3df675a3125a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_MEM_BASE_BAR5</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac05d0391a0ad234b61ecd895054e8443</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_MEM_SIZE_BAR0</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a8fca1cce810bcaa4b616c1caeee7a9e4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_MEM_SIZE_BAR1</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a0afcefcf7156a1c72555b8f77ce4f9b5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_MEM_SIZE_BAR2</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a51576e7010559c7dc3e16e503ec318cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_MEM_SIZE_BAR3</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>abc28011e76096a14e502649947fb301a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_MEM_SIZE_BAR4</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a8b5f342653a360dc2151c7f09e4287ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_MEM_SIZE_BAR5</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a6336ecff947597fef74bb2bd43864a68</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_IS_EXPRESS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>af99b701452410273c0c978bc901da73f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_SLOT_LWIDTH</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac2defcb280e0865274a25da974a17c54</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_MAX_LWIDTH</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aaf11441c976a8d448308808af17abd01</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_ACTUAL_LWIDTH</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab5f09dcbe5a5d71a2dfc5f4dd591035c</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_DSTAR_BUS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa8dac94dd3342892480c3e638721a6a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_PXI_DSTAR_SET</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad2e404aecf5566f02d3529e96093c83c</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_TCPIP_HISLIP_OVERLAP_EN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a600dde04ffb50cd9ac8a6869b1a68fe3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_TCPIP_HISLIP_VERSION</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab2c9b580293d82795329cdf3295608da</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_TCPIP_HISLIP_MAX_MESSAGE_KB</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a78e4a3672417a52529c1e0ac3ac762f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_JOB_ID</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a2fa21d6667fdf2ff4b092e305166093e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_EVENT_TYPE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a96e5add16d3bdd1f19745d1f3ac53dd2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_SIGP_STATUS_ID</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac60c9352e192b54d1992751832c4de15</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_RECV_TRIG_ID</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad14e6ecc6d3a6dcc718a1547cddd782f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_INTR_STATUS_ID</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>af45f03ce22bcf3e54a1f008573e50e23</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_STATUS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a9eca480a38daa062da6ccafb53b6a126</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_RET_COUNT_32</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a7fe0a906268162ce1267913a33671575</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_BUFFER</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a62a34327980b47d9bc132efddb5b6fc2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_RECV_INTR_LEVEL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a48cd1f19cd5218e737e9ba824e7835cb</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_OPER_NAME</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab89279e20a610a3600a62072b90e581e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_GPIB_RECV_CIC_STATE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a491cde91d0381d78bfc80cf544875a96</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_RECV_TCPIP_ADDR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a09ce430716e929c96c0574044c7432da</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_USB_RECV_INTR_SIZE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a55409b6329fdb8bae12a27faa2007acd</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_USB_RECV_INTR_DATA</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad6bbb2f97b9409e37f9bda0b11f3fcaa</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_USER_DATA</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a93d605ea45746b4ec327399d89d993ba</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_RET_COUNT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a9c3cc510b33dcfecbe44cdadc4f549d9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_WIN_BASE_ADDR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>af4add1e3f1cb88e9f0238261118db2d7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_WIN_SIZE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a43141f24c70615aa166cd597164c71c9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_MEM_BASE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a4fdd05d2d7a4db9019b5eb9c282e6250</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_MEM_SIZE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a363e449ea28fd3e7f92742c204b26226</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_EVENT_IO_COMPLETION</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac292d749b2b9a59824186285c620750c</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_EVENT_TRIG</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab7cfc09f8bc8bb9dd5f4fe214ecec156</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_EVENT_SERVICE_REQ</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>adef62cb944209bddd8b41907efb5ee9c</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_EVENT_CLEAR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a3c6be8cad19996580ea21edb93f87325</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_EVENT_EXCEPTION</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a571e0bea86c350489dc1cf729c9fd981</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_EVENT_GPIB_CIC</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a640df79ed34392aa807c720bf830692b</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_EVENT_GPIB_TALK</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a2bea0dbf41d1eb0262e687c4c3888e7f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_EVENT_GPIB_LISTEN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa5973312285ff1b88a51017df28f42e7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_EVENT_VXI_VME_SYSFAIL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a11ca76b66f9d1ee6b902ee398d55e936</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_EVENT_VXI_VME_SYSRESET</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a2e890b4f8694419e51283a5cad2bf61e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_EVENT_VXI_SIGP</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a6abc3774b6bf8b2ac52290ab7aad77c5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_EVENT_VXI_VME_INTR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac96314f6e7def2e49450249f3f6d5d41</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_EVENT_PXI_INTR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ada7da05125d1a517775ae1afc765aec6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_EVENT_TCPIP_CONNECT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a73d45f520961be97a474d039ae5735b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_EVENT_USB_INTR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab165381611a3e5968879747ee34fa377</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ALL_ENABLED_EVENTS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a865c1180a76e2d2d07625c3898f3ac93</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_SUCCESS_EVENT_EN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a8ee0300ea88f31ed538f9258db4e9091</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_SUCCESS_EVENT_DIS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa5bb82c92ff4e341034c6dce9d360cc6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_SUCCESS_QUEUE_EMPTY</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab20fc669b49ac45a324b027caf4e53dc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_SUCCESS_TERM_CHAR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>adeaa30aa76a1d62a9a2cd07c507b6ec0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_SUCCESS_MAX_CNT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad092a341e568a5a456b0e7bbaee53423</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_SUCCESS_DEV_NPRESENT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a4ad3823b3bced23dbfa41f0b1d0e69df</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_SUCCESS_TRIG_MAPPED</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>adc05c67ae6d6fb3027b738ab41e51d20</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_SUCCESS_QUEUE_NEMPTY</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a22e00babaa92253aa05b085a5c43daef</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_SUCCESS_NCHAIN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a9eb7ec8a260ae5df8107f5b252a59bef</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_SUCCESS_NESTED_SHARED</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>af36e227d953164952e20f8ef0177faee</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_SUCCESS_NESTED_EXCLUSIVE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad500c9f735feeec8dbe31fadf321ae98</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_SUCCESS_SYNC</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a68851a76d27d9347cb6daa0b70577560</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_WARN_QUEUE_OVERFLOW</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a3f3af395f8e0317660dcc4d72403410b</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_WARN_CONFIG_NLOADED</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a749aba65ed5908520491998cd3a29f40</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_WARN_NULL_OBJECT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa301568a468a1fe1cfe052aff40a4910</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_WARN_NSUP_ATTR_STATE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad8c445b120b9c519224d1927f303a211</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_WARN_UNKNOWN_STATUS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>af5d1a9973e5b2964f20aea9161f03553</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_WARN_NSUP_BUF</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a8a1b9d12e3701f2f3a2a55f0dd9e616c</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_WARN_EXT_FUNC_NIMPL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aff8b7c4814029472a12331ed28b6d8fc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_SYSTEM_ERROR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aac078af8eb1bbb716a24a66c2f10e393</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_OBJECT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>af5a7a6b671e3457cb09e8bb7a164b007</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_RSRC_LOCKED</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a0f84f7e5ae4d3f1201623f12a03c4c59</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_EXPR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a7c26ffd5d404c9833f1514d50b4bff39</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_RSRC_NFOUND</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa27a4d438337c66d5353cf571c2f977e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_RSRC_NAME</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a0558d342ae6fd88392c78f4a19bb567d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_ACC_MODE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a51a80a3ec19dc527161e66028396c66b</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_TMO</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a095fa1749ee8d023dbe1f5a388c2409e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_CLOSING_FAILED</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>add16c06902253fe0779d0e95108d3d54</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_DEGREE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>addc959cea50caa503f767b29c792c9df</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_JOB_ID</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>acc4b1ea921b6314d5d782d2a12ad0135</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_NSUP_ATTR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a9a7fb2591b64dcc79fc1fbec3e41f1cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_NSUP_ATTR_STATE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a97c3d16dca5c0b17cca84843c40b5910</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_ATTR_READONLY</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a10719ec45196a89bb372b3c154c73016</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_LOCK_TYPE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a503285ecea037d9ea71b83b9a0cd36aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_ACCESS_KEY</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a051fa4e683afdbc51432d75d12c1c8fb</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_EVENT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a19ea7d30616b92f29d841d259b72f74f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_MECH</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ada222b7a4c7c3d2d15e763b06f40bc46</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_HNDLR_NINSTALLED</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a0aff94711acf7d13dfa4129386c7185f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_HNDLR_REF</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aab720b0c212565858b388bdda13a1c11</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_CONTEXT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac8a05e9d5ee05cc87100d44fb96a69c5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_QUEUE_OVERFLOW</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a4ad7b0aa446b4c80771fb73d9182edec</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_NENABLED</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a9fd3130e0bf1bdc19b5abcd3e5c1def8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_ABORT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a0ab888096362395b23f1589f430cf2d2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_RAW_WR_PROT_VIOL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab87b96cfeece22b50f4f115a615128a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_RAW_RD_PROT_VIOL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac89959a565b21aed8e59e8a751f4edad</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_OUTP_PROT_VIOL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a0769006e4ce20da6a31a1d82aa885803</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INP_PROT_VIOL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ae87542297ad00c75a9c53a1a461123d3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_BERR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a2ac31a0fe441ee44aa830d7444155fdd</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_IN_PROGRESS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>af36d37c0155c8295f3e2fd778f2a5775</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_SETUP</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a104c6be498ae53d0a2a12278e9949d2e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_QUEUE_ERROR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab082352d97664ad03fef94738d5ebfc2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_ALLOC</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a7bbf1c105e8054baee749872ab0c0d72</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_MASK</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>affce59ae7255ac37e41018fd21fb93a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_IO</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aea42b5a8b628b1305776b96e51638896</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_FMT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab90b1520d9665488fffb1f6bb551af99</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_NSUP_FMT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a664a6aa973cf6332353290acfad28996</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_LINE_IN_USE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a2080d145c072457f2b9334d5a2c97b21</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_NSUP_MODE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a5c9a1bca85294ba9da9a6c93ebeff1ac</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_SRQ_NOCCURRED</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a4e3fe32fe055fb9262364a83dda7c8d4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_SPACE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aafabafbb75f325b639ca33ba1faff551</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_OFFSET</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab8324c558d707ea8ae537cf2dea3b808</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_WIDTH</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a4f2e369b75c45a6c4a6bc46c505be049</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_NSUP_OFFSET</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa365e013bf7fb465efd450056149fb0e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_NSUP_VAR_WIDTH</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a7304bd0b73bd0c5545619d57b158541d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_WINDOW_NMAPPED</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aedab4e3aba9a4f8b205071e117dfbdc0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_RESP_PENDING</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a1fa4ae114654a7ad0ff6e9362bb9fd1a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_NLISTENERS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ae4b8974a26da1268fd712c3d19f870b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_NCIC</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ae480b2075cf20bbcf5294b4fcf47a049</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_NSYS_CNTLR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a26327490c8b2f1ed91b101baf0330297</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_NSUP_OPER</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a115aebbde1cce8e438032ce64d894310</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INTR_PENDING</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a57e278f8f9f11fbb605d10e9898f0e31</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_ASRL_PARITY</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ade949a4408962485b7ff06b89e1005bc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_ASRL_FRAMING</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a53c68b395133c9ae463bb6eccbcd73a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_ASRL_OVERRUN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac54473146550316c90ea35224e74feb8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_TRIG_NMAPPED</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a7e5f3202be0e7f7682756952914aa472</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_NSUP_ALIGN_OFFSET</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>af1b1deca2b5e0f4c785058282e2df9df</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_USER_BUF</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a8c69d00e70df804f0514c6170a3cf139</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_RSRC_BUSY</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a34f6c4192365ec97461d3b5a917d3255</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_NSUP_WIDTH</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a1539e9df06b9f48a8f6d1ec97fd9ba61</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_PARAMETER</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a2177371edfd33c19706199799f84a231</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_PROT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a37469f057042aa46dfd17a1753e3239e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_SIZE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a9f34b294c02e8c8f1940c21edadb3fec</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_WINDOW_MAPPED</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a774651c96ae39a819d368b55e633ef95</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_NIMPL_OPER</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad79fcbe4854687d2fb41963b8a85cb8e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_LENGTH</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>afd16846fd30e699aa605e2b055c22755</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_MODE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a518ac9c75c4df182c26e0a95e1297885</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_SESN_NLOCKED</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac328bcba18f427bc32a38000e636e9b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_MEM_NSHARED</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a610812ccce305890cbcd51bff8fa307f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_LIBRARY_NFOUND</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac54deee8e7a5dfc0411c907557a8337e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_NSUP_INTR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad0c7674f80319ae1230e3835d1c84afb</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_LINE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab2dc4d6fdecdee9eb840d0d33fefedc2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_FILE_ACCESS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>acbbe69eb9a29f050e76ff49a8da03b1d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_FILE_IO</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad0f4d8823bde309ed01aa773e22f20b8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_NSUP_LINE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa79a66d4f88b55e50afef381e3c7ca99</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_NSUP_MECH</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a963a4a5661ff69d6b28409264e70bdf8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INTF_NUM_NCONFIG</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a2065c267cd23d77f51e331844fdec34d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_CONN_LOST</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a62e1704399bfd47657321bed8fc730f7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_MACHINE_NAVAIL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ae55327353bd270a8e57a62202a97255f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_NPERMISSION</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a5f2b3fbe79b9aeb4db637b9a9e376cec</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_VERSION_MAJOR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ada62d0b3a5e171d0428c7ad40a3b1669</anchor>
      <arglist>(ver)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_VERSION_MINOR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a742257a92fc1d030b1626c814e1b3683</anchor>
      <arglist>(ver)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_VERSION_SUBMINOR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a372b7b5d9885ffe1162253c46c238657</anchor>
      <arglist>(ver)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_FIND_BUFLEN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aac4226b27ebfa5b58467c3b277323176</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_INTF_GPIB</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a5aa9a250840f536636634078f369536b</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_INTF_VXI</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad175da42ad67727da27533e3694c31df</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_INTF_GPIB_VXI</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a6664d0ee7a4fdbebed07b6937739a2bc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_INTF_ASRL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a23efe7bc2a95e1d1b9311758b8304fa8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_INTF_PXI</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>afa425d4e07f369ecce2b4d6d067d43f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_INTF_TCPIP</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a26b5a0f79e27226cfbe2ac96c32a280e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_INTF_USB</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a1dda362951f8ff7653647442f05a6bec</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PROT_NORMAL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a80b18ae8eb16908bf093aaea53f9a7da</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PROT_FDC</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>abf6e8f5c3cd4ddc3e89554da12d8b12a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PROT_HS488</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab4c9bb3122a998436b42973482ed6cec</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PROT_4882_STRS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a757755c26455c38e9e5887963e84a506</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PROT_USBTMC_VENDOR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>abb414459466130571fdb97e987ca7ff1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_FDC_NORMAL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a48e3cad1dfa10222306d0941c38e82b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_FDC_STREAM</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aaffdbb7f2502dda2f61c30259b6e05bd</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_LOCAL_SPACE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a168bf6616f33ba4eb078c54b8ba1e178</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_A16_SPACE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a91a9c5f241f5bf84882072af84eaeea4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_A24_SPACE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a2359a5f952246ee41fd10358fcdf6d85</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_A32_SPACE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a183d031172ea965c94511a3ec86d22f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_A64_SPACE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac724c25b8b95e0778afae3bf5b863a6b</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_ALLOC_SPACE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab60e75d3f207dc54c2ea8863bece8cb4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_CFG_SPACE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a6125963562ea04d741f52f5119b944bc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_BAR0_SPACE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a4f0af7c4f18301c85618655195f24ac1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_BAR1_SPACE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a6c5da28969d9eef9caf3066f889e8bc9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_BAR2_SPACE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>abae386dbc54a440010190f7b133ff045</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_BAR3_SPACE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aceb810f12bf23013ebc557c3bcd0aa3d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_BAR4_SPACE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ae448fa6d06f53abe1f6c56f11d6694e2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_BAR5_SPACE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a7d36e3935e5e8e3063a9bd378767efe0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_OPAQUE_SPACE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>acdeb9c245bd2f846ab3e0e54b9ee2c3f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_UNKNOWN_LA</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad3ad1b56a686e27043198f4bc3d10e3c</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_UNKNOWN_SLOT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a1a82a101b333293681c680252206276a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_UNKNOWN_LEVEL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>af4b80600f497ec0071d6c68984cc2d0b</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_UNKNOWN_CHASSIS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a3b04662d936b7acadcfd66224c5cf1e9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_QUEUE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a6d636911b0df938347b9900d9d93e358</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_HNDLR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>afb305c7ae68e5a9e08a50a403febe62f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_SUSPEND_HNDLR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a8013f5756f523251b4ad49af51ef3780</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ALL_MECH</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac3b3133575eeaf9dba8c1ab40a766163</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ANY_HNDLR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a58e018d9afbb5f63a2b20437e424eae8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_TRIG_ALL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a4f2aeaed6210a3db5a9a6427a659caf1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_TRIG_SW</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a463914d9956a7b3f4c55ab2958bc1ccc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_TRIG_TTL0</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a65d2e94a3527d5b7998873a64cabc842</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_TRIG_TTL1</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac3c79bbf4f8993d83303ba2a3cf22fe0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_TRIG_TTL2</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a2bf4408a017521ba8e0b012c75721416</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_TRIG_TTL3</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>acebfb24a5a50d97456b01e0f85037536</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_TRIG_TTL4</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a47def2b49507f65aa63026a8744de6b8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_TRIG_TTL5</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a7977cbb779b2be06d22d563f0dc26910</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_TRIG_TTL6</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a3d8ec327e56ae2eba4b8f04a806ae362</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_TRIG_TTL7</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a2b43ed2c459cb952f9d024b6a89b5ce5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_TRIG_ECL0</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a4e766ddb417076efb4e0bb60c7282a77</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_TRIG_ECL1</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a87ad279fbfb63d808aa3f4d0978ded60</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_TRIG_PANEL_IN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a51aa173264d7804d41b077489a1eb107</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_TRIG_PANEL_OUT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aead2a35e6c1406751c8b2f59cd7ff958</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_TRIG_PROT_DEFAULT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a7acac2ba99f6f8c1d763909c3d92add8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_TRIG_PROT_ON</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a0d9a982e8b2caed11105746ace87d525</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_TRIG_PROT_OFF</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a9a0a67d179b32ed52fbf31a0eb754999</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_TRIG_PROT_SYNC</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab34fdec69fc7d7d046708436a008472c</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_TRIG_PROT_RESERVE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a03707bea81dd4ba7f865ced52c8b4e78</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_TRIG_PROT_UNRESERVE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a574302d21af9612691171bb0888371e2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_READ_BUF</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a4bafb7935b616b8dba236c5a3dcbb6df</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_WRITE_BUF</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a5f616fa1b4f763f2d7f88bce1461f75a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_READ_BUF_DISCARD</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ae9729f263aa838859e752e27fed4beea</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_WRITE_BUF_DISCARD</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a6088aafed62c7beb8075905525a0155b</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_IO_IN_BUF</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>afb4a281c622aaa4966a2e3b8638ab3ae</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_IO_OUT_BUF</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a848a35cf296b3baf092c25ea9599a871</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_IO_IN_BUF_DISCARD</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a1c75f5790928f5d3adfe321baa7305cb</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_IO_OUT_BUF_DISCARD</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad292f1aa97f0534387eb669911fc614e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_FLUSH_ON_ACCESS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a98a8d2d074c9479a4dff49ecdf98bfe2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_FLUSH_WHEN_FULL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>af4de7c8a65a6374026938f2100eea324</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_FLUSH_DISABLE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a66d8542e38b7f315f7b63ccb1f6ab964</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_NMAPPED</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aab89db03b8130c04b3c1ae4f8770fca0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_USE_OPERS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a921e6f810b1fcc34f82225a15a55ab68</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_DEREF_ADDR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa8e5b510ba66992a3e1fd105e40acb84</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_DEREF_ADDR_BYTE_SWAP</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>abdabec2d18f0905d4fd2a00185770688</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_TMO_IMMEDIATE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a3d197e8a724493cb52115da152622c23</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_TMO_INFINITE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>afeb24d6068b23d1db8202898cfd2e5d5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_NO_LOCK</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a32a4648916027bb39ee3cf8b5557e5a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_EXCLUSIVE_LOCK</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a3d67ccaebcceed9e01b720a7b88da866</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_SHARED_LOCK</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aead48aac0be7512f3847376a6e6b13e1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_LOAD_CONFIG</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa5eb2e4bec978317d0c32218aa7e2f5e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_NO_SEC_ADDR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>acfbfa49f31879658c08f69fa073219a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_PAR_NONE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a5b6096211b12a398889bfa67b0d469fd</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_PAR_ODD</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>af87ace6732faaac7499b6beacd96bcc2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_PAR_EVEN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>abc94dcdbe51dac522ea7aeee6ae4eff6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_PAR_MARK</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ae8555b2616947c4157c1a0c371607777</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_PAR_SPACE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aefb06213484c85f316ab68a9a7696721</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_STOP_ONE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>adf35b0e9c5718b6aa3ad5ce3611c3808</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_STOP_ONE5</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a8253235002291c387e24f93c046bad2b</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_STOP_TWO</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a49756a390b9bc76cdae14ae6d2018505</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_FLOW_NONE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a6f37f8dfe038080e7ee0632b39284a1a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_FLOW_XON_XOFF</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a6bd38c689bea863145c2ca6cf0bb5a48</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_FLOW_RTS_CTS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>abfb72a4de647ff48d3a6aa5116ced0d0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_FLOW_DTR_DSR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a2789f5fd3633882d0f132e52d1a49007</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_END_NONE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>abec93c4f2730dbffef6dfb1c80760b44</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_END_LAST_BIT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a41e0b73f68aaf6044920b12188f246d9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_END_TERMCHAR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a502ecac4048f2992cf91585a2a7424b6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_END_BREAK</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ae605a2a06297a740f56de87b996bf220</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_STATE_ASSERTED</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a5f386cdc3a8612f5b7d6417fa7f87bce</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_STATE_UNASSERTED</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa24e9dbb88810f4a6ccbaaffa743b678</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_STATE_UNKNOWN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a0f9e50086a726938df9cd05e1511b09e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_BIG_ENDIAN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab3b5c1d2cf19e1b35b5c3847f0a05cae</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_LITTLE_ENDIAN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad78fe64cfbdb8ed8e63cde69ad9a9646</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_DATA_PRIV</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad336ffbc53f5ee71cf27484b4ec7bb20</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_DATA_NPRIV</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aaf3696b58635af377802eb9bb86fcc8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PROG_PRIV</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a3ebc0c6608838af7d18cd881a282917c</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PROG_NPRIV</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a5d943e04e47143db6d3d81208176182a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_BLCK_PRIV</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a94be9086ec6779a2fa47c24cc3be34e8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_BLCK_NPRIV</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a75adcecced40418ee7d001a93abc0594</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_D64_PRIV</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a85185c7052285157288e8a04102303e2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_D64_NPRIV</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>af79dec24f0904829e70f816e77c098dc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_WIDTH_8</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a79081625049b7fca9ccecac937f5c4ff</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_WIDTH_16</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>adf74c26fd420d67cdfc2486f889d14fd</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_WIDTH_32</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a71f1df26cb3778208ed8a88ed0789ad0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_WIDTH_64</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>adeee30d363febecb945198227e8e2a79</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_GPIB_REN_DEASSERT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a055c3dcf0cb913992404c9feaf2d34c5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_GPIB_REN_ASSERT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab203a8e04066058767dd2b5518bfa5a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_GPIB_REN_DEASSERT_GTL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a8cd1e9af7f60d38b517445389a9ed816</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_GPIB_REN_ASSERT_ADDRESS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a4e0fd009007d1bb8441666d4497544cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_GPIB_REN_ASSERT_LLO</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ae0c193b2354cd06820536ea1404aaa45</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_GPIB_REN_ASSERT_ADDRESS_LLO</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a84fed0cdf8dfe48b839912817639a7fa</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_GPIB_REN_ADDRESS_GTL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a45631114b3ac29d21a0bf43c3ba2b8ac</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_GPIB_ATN_DEASSERT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a698e9656bd84ac44404e901534a426e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_GPIB_ATN_ASSERT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a23f66b639c9ea2bec23072e072c07ca0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_GPIB_ATN_DEASSERT_HANDSHAKE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ada776e521af5f8bef36282659f8443c0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_GPIB_ATN_ASSERT_IMMEDIATE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab22200e7ff492112ae423ac90c79e4b8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_GPIB_HS488_DISABLED</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a0977479ff320381fd750653f1de4b0e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_GPIB_HS488_NIMPL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a469f369267d9b3533b62838683ada9a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_GPIB_UNADDRESSED</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a15af58deee8be12439e03fbc270249b7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_GPIB_TALKER</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a813eb7b8c3efe2e470cf75e384239a19</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_GPIB_LISTENER</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a226e8262c1b25cba2fbd5a8a47e49ed6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_VXI_CMD16</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a6136e9a855d08ae11d33da6733422ed3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_VXI_CMD16_RESP16</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a45215ac61d825c9538334ac3ddf45c76</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_VXI_RESP16</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac326bf9d51337bd8c62ba164cd9810b6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_VXI_CMD32</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a8b194df930da7fb3d1cee569d64d1c95</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_VXI_CMD32_RESP16</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a42b29ec39c572068fd4ef231052d81cf</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_VXI_CMD32_RESP32</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a2832e45fe50379403fc740c6af2d2db4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_VXI_RESP32</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a4b8552dd826d85210d3d5bdf6d050d15</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASSERT_SIGNAL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>afec4b708bab63f16b1bd8d05ab79eb5f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASSERT_USE_ASSIGNED</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa688958cbdaa21cd3b0948d96b6a02a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASSERT_IRQ1</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a1a2871260c45b558e34a37f8cf88330d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASSERT_IRQ2</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ae50ffc5512eb45b615d80a7c969d35ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASSERT_IRQ3</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a60d09c87417e1e1a092d791f5ce3c738</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASSERT_IRQ4</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ae1e426ab08a3b8cdf205af526e03becf</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASSERT_IRQ5</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa44c7bc8c2e47f6355cbfef517a630ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASSERT_IRQ6</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>adc1985c090b5cbf11abcb3199a1f96ba</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASSERT_IRQ7</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>abf393c6be5effc87f87bfb4931d6e5fb</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_UTIL_ASSERT_SYSRESET</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa0f955848127346188677542a4ed7c71</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_UTIL_ASSERT_SYSFAIL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a4dd21a643d501652f46a39ccc906f724</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_UTIL_DEASSERT_SYSFAIL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab8622e7c2dc8c9c868b14fa451cf6948</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_VXI_CLASS_MEMORY</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a096584a04d6ed2a7afee4412384471c9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_VXI_CLASS_EXTENDED</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa9a0f1e6d28107b7a3625faaf7d070ba</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_VXI_CLASS_MESSAGE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a3c63515755aba95ab8e7e861504c37ce</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_VXI_CLASS_REGISTER</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a57ebbbb713e58a58007809595e87fa1e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_VXI_CLASS_OTHER</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a73eeb1144fa06441d35bb7a999046013</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_ADDR_NONE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a91aabcc493487b6812dd68883a1f147d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_ADDR_MEM</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a9b75eb1039942263edeec8ecfe2daf11</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_ADDR_IO</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>afcb777710f57abb77c8daa4d92c71dc1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_ADDR_CFG</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>af1b30363d23698970999a3eeb74eb1bd</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_TRIG_UNKNOWN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab634420eada89d2a2a29059e506e2315</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_LBUS_UNKNOWN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a720fc816f74adb0e35041bb4e5b1c81d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_LBUS_NONE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>add4515fb87b84d2aca3b9a4e6cd12a33</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_LBUS_STAR_TRIG_BUS_0</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a5f9578c39979e5769694c61d08e1d2ea</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_LBUS_STAR_TRIG_BUS_1</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ae7a5f16d7364aa1d5a6e23296c72eb15</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_LBUS_STAR_TRIG_BUS_2</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>afbc25b9e02ffabad3e70b7618d78baaa</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_LBUS_STAR_TRIG_BUS_3</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac7b694d664958fbcf4a96e5855e3fb9a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_LBUS_STAR_TRIG_BUS_4</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a5913f185a3720e652a7f5675acde401c</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_LBUS_STAR_TRIG_BUS_5</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ae7c0e058e271ff7e112c49a73ac54f52</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_LBUS_STAR_TRIG_BUS_6</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a88bcf6f8426d48e1870e8723f31ac1db</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_LBUS_STAR_TRIG_BUS_7</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a97d5a73fee7c86e613d25035bcd303e1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_LBUS_STAR_TRIG_BUS_8</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aca9b80ca22c568cd4bf3c4893ada5f92</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_LBUS_STAR_TRIG_BUS_9</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a9b667a78a4b23a783e77188a8972d701</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_PXI_STAR_TRIG_CONTROLLER</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a0a5fbedd617a298ad5e21a5fe6bcaf26</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>viGetDefaultRM</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a31b05f4259c40a283c953ad71648c33d</anchor>
      <arglist>(vi)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ERROR_INV_SESSION</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aada3508150b321e4d393e65dd51db7e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_INFINITE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a89ab9caa40aa7ddae2042aea919680d1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_NORMAL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a5a5ff111f78cb9e3e99000844e475f37</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_FDC</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aee044520a3d9f27f1b35ab280b310a57</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_HS488</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ae9c41cd0bde400c67f8b3dfcc9939f74</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL488</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>acfc1d9a9fe9b8e34fa06de5981bf084b</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_IN_BUF</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>afd90595d52206b98e9d8300aacb6426a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_OUT_BUF</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aaa14679b0526afaa86706c1bb612ce20</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_IN_BUF_DISCARD</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a8a4b3a45fb2fe080183770efa8ed70d9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_OUT_BUF_DISCARD</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a97603234fbc456bd69f6450fd1abc1af</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_INTF_RIO</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac3d580665added0e27fe7b2e6c3cba55</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_INTF_FIREWIRE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a4a3fa9e43287d0b41c3fc2bccd44d3b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_SYNC_MXI_ALLOW_EN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>abeb7dda76ca77b2c2af75c45c3c0ee33</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_EVENT_VXI_DEV_CMD</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a8707ebed9c07ae029ea28ed7dbe3c303</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_VXI_DEV_CMD_TYPE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a2be4d11c4b34a157f701c0672d55a3be</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_VXI_DEV_CMD_VALUE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a751df0b33e67066859032f05678455f1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_VXI_DEV_CMD_TYPE_16</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab76a7b69c5277b25de4ac349c0256254</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_VXI_DEV_CMD_TYPE_32</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>afd6732c793b4d2184c8c41ba3a3c4134</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_VXI_RESP_NONE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac22245e6fa86edf5233c2367fd31972d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_VXI_RESP_PROT_ERROR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a732d10f0706b644597531b287d7ef2bf</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_VXI_TRIG_LINES_EN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ae224a883a211b0a467e1f328c2318a17</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_VXI_TRIG_DIR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a4bd32e864c0736141da37604baf5c399</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_ASRL_DISCARD_NULL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a258b0344c6c42399ee219f4164a592f5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_ASRL_CONNECTED</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a81e42cf07be1f39ab38d6bed820c6732</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_ASRL_BREAK_STATE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a3238768a6219691260be2fa442664b43</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_ASRL_BREAK_LEN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a207e16b506aad949dfe4a393bdd70c2c</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_ASRL_ALLOW_TRANSMIT</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a89814a2e2e8dda168e84d1184a4f5600</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_ASRL_WIRE_MODE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a8ad7b3cc1c2f65f84e76b12ed742926f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_WIRE_485_4</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a01cb3f16918ab66102457231ed5089cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_WIRE_485_2_DTR_ECHO</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab93f73047c215412bbd07ca64ec5464a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_WIRE_485_2_DTR_CTRL</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab5df26280ec64636b88fec3f487e8a3e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_WIRE_485_2_AUTO</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a7d9209d3745bedd893f3ab76eed47248</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_WIRE_232_DTE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a95fe3e2dde1b2bf89cd8defdabfeb8f4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_WIRE_232_DCE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a7c862db74a48af3ca57d71908aa77cc7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ASRL_WIRE_232_AUTO</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aafad8945419a11af419e7a8eb854adaa</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_EVENT_ASRL_BREAK</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ade65e60dd0a7debda22817d63f9268dd</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_EVENT_ASRL_CTS</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a55e6fe77ec3df6983a50074c0d075465</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_EVENT_ASRL_DSR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a314eecc11a618bcb1b0be885406de7e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_EVENT_ASRL_DCD</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a575bbc74a3217238cef95ff9c5252d76</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_EVENT_ASRL_RI</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a0573c4f138e70ff8bfa14a8c16e9ee92</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_EVENT_ASRL_CHAR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a7c9d7c809161a5dba51419134737172a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_EVENT_ASRL_TERMCHAR</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a3006d702d1e0e380a6e46086e47986c3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_FIREWIRE_DEST_UPPER_OFFSET</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa9189a9dc1218f35ae53217f881c4d76</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_FIREWIRE_SRC_UPPER_OFFSET</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa56997377ae5f5a4760d074ba0367280</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_FIREWIRE_WIN_UPPER_OFFSET</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>adf024a69d1982ae2f4448d0a90498e01</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_FIREWIRE_VENDOR_ID</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ae11ec5d0b3d19d0d43a293bbf566681f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_FIREWIRE_LOWER_CHIP_ID</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a22b4a7d59245f5744a9c1ffc2ffe4d91</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_ATTR_FIREWIRE_UPPER_CHIP_ID</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a1eac4e06eb4292ac57b5c57fcab73928</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_FIREWIRE_DFLT_SPACE</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aae10866bf7f35ba547356149655a3917</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViObject</type>
      <name>ViEvent</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a344530d326baf4406e16e53cd2c61fb4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViEvent _VI_PTR</type>
      <name>ViPEvent</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a495e30540346946f3840239a118f2a8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViObject</type>
      <name>ViFindList</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a194efe6afb7f6468b2da8ca8578c9c9a</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViFindList _VI_PTR</type>
      <name>ViPFindList</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa1cf386be7ab335e9875e3536c003d5a</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViUInt32</type>
      <name>ViBusAddress</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a825852ca7463eadf49e9d54afe94bd7e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViUInt32</type>
      <name>ViBusSize</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a9d9580f83b3b5731ae1f445c1995e9be</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViUInt32</type>
      <name>ViAttrState</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a8bd3a8348386547fd76278826f70ca68</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViUInt32</type>
      <name>ViEventType</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a8231ea920158c00072ec3882a5f83cd3</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViEventType _VI_PTR</type>
      <name>ViPEventType</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a4652eb6bca70a1dd5140af3fce6d9980</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViEventType _VI_PTR</type>
      <name>ViAEventType</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a4951ba7ad0824a59ea428783fab264b8</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>void _VI_PTR</type>
      <name>ViPAttrState</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a8431a0a74717bc4cc8254e50071b6269</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViAttr _VI_PTR</type>
      <name>ViPAttr</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a4e4d24c929ae5093e8f0a77bf04e4531</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViAttr _VI_PTR</type>
      <name>ViAAttr</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ae8d84e9924cbf2772554a58aa95a8e62</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViString</type>
      <name>ViKeyId</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad3be30598dc0ebcd4d0c1c8b396f53ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViPString</type>
      <name>ViPKeyId</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a921aaacdad15682fe992a8ecad2ab12f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViUInt32</type>
      <name>ViJobId</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a584063b4815435814828c44d862245ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViJobId _VI_PTR</type>
      <name>ViPJobId</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a508b9d3343d108955fbff733c7d932a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViUInt32</type>
      <name>ViAccessMode</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab21e429c25b9ffc3a4dcf9f180651456</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViAccessMode _VI_PTR</type>
      <name>ViPAccessMode</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a1687e2af071a83065bd3fd76c402286e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViBusAddress _VI_PTR</type>
      <name>ViPBusAddress</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a003afcb06fbd350cee31460223690627</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViUInt32</type>
      <name>ViEventFilter</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>af8bcf8364c5e432835ce991c3da0855c</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>va_list</type>
      <name>ViVAList</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a5737db08fcc362874c6ac823b5ee7cab</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViEventType</type>
      <name>eventType</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a6dc668b88ee840cd0ee2e069b7581e42</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViEventType ViEvent</type>
      <name>event</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a5020215c7f11857df5dafd6f9c677a49</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViEventType ViEvent ViAddr</type>
      <name>userHandle</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a45395a6feff159e1ff825afd26ed9d6e</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>typedef</type>
      <name>ViStatus</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aeef5abf31d421d5635336d2d21980ebf</anchor>
      <arglist>(_VI_FUNCH _VI_PTR ViHndlr)(ViSession vi</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viOpenDefaultRM</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a60c3d716b7431905e75c962449773ea5</anchor>
      <arglist>(ViPSession vi)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viFindRsrc</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a628660c1047bcdf26477e491a052aee5</anchor>
      <arglist>(ViSession sesn, ViString expr, ViPFindList vi, ViPUInt32 retCnt, ViChar _VI_FAR desc[])</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viFindNext</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a6a70714d71d9c0becb499fb6efd1b0e6</anchor>
      <arglist>(ViFindList vi, ViChar _VI_FAR desc[])</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viParseRsrc</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa10976454f0e435b652884c87448dae8</anchor>
      <arglist>(ViSession rmSesn, ViRsrc rsrcName, ViPUInt16 intfType, ViPUInt16 intfNum)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viParseRsrcEx</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac87376563f1fe3ac9b05ab4e972cacae</anchor>
      <arglist>(ViSession rmSesn, ViRsrc rsrcName, ViPUInt16 intfType, ViPUInt16 intfNum, ViChar _VI_FAR rsrcClass[], ViChar _VI_FAR expandedUnaliasedName[], ViChar _VI_FAR aliasIfExists[])</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viOpen</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a9bfb64a2b059f9e78d2c1ff21f1171c3</anchor>
      <arglist>(ViSession sesn, ViRsrc name, ViAccessMode mode, ViUInt32 timeout, ViPSession vi)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viClose</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac7f8e3a1817b04c813e80bee1a9360fa</anchor>
      <arglist>(ViObject vi)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viSetAttribute</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a5c8ee5dfd71472901ffdcad5790945d7</anchor>
      <arglist>(ViObject vi, ViAttr attrName, ViAttrState attrValue)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viGetAttribute</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>acc32a8b0153a7de9a6b1f7290611d31b</anchor>
      <arglist>(ViObject vi, ViAttr attrName, void _VI_PTR attrValue)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viStatusDesc</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa9c0943bbe4343be3e86a0ddb20d43a5</anchor>
      <arglist>(ViObject vi, ViStatus status, ViChar _VI_FAR desc[])</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viTerminate</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>affa00de9b7cb52de0e10712443c9a311</anchor>
      <arglist>(ViObject vi, ViUInt16 degree, ViJobId jobId)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viLock</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>af9f63a8b9d68bff54692a5191766241c</anchor>
      <arglist>(ViSession vi, ViAccessMode lockType, ViUInt32 timeout, ViKeyId requestedKey, ViChar _VI_FAR accessKey[])</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viUnlock</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a984e7fdef362c27d0657d137a097a26c</anchor>
      <arglist>(ViSession vi)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viEnableEvent</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ae156c6eb1a79cd4ec1450026f429db0e</anchor>
      <arglist>(ViSession vi, ViEventType eventType, ViUInt16 mechanism, ViEventFilter context)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viDisableEvent</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a92be3f9f0eaa9e3a15613048fea72d09</anchor>
      <arglist>(ViSession vi, ViEventType eventType, ViUInt16 mechanism)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viDiscardEvents</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac5c83a9c56a20226db954983eca14492</anchor>
      <arglist>(ViSession vi, ViEventType eventType, ViUInt16 mechanism)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viWaitOnEvent</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a6e6d6182014878c8662a17e8ab724e39</anchor>
      <arglist>(ViSession vi, ViEventType inEventType, ViUInt32 timeout, ViPEventType outEventType, ViPEvent outContext)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viInstallHandler</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a0f799e20dc7aafc8d81c12c69ef2bfea</anchor>
      <arglist>(ViSession vi, ViEventType eventType, ViHndlr handler, ViAddr userHandle)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viUninstallHandler</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aeddcd9c1b594fb9d70248587224f5834</anchor>
      <arglist>(ViSession vi, ViEventType eventType, ViHndlr handler, ViAddr userHandle)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viRead</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad8f1884071448162bf453b5928784897</anchor>
      <arglist>(ViSession vi, ViPBuf buf, ViUInt32 cnt, ViPUInt32 retCnt)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viReadAsync</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac4b5781ba1e70c97da737a9474c67ecd</anchor>
      <arglist>(ViSession vi, ViPBuf buf, ViUInt32 cnt, ViPJobId jobId)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viReadToFile</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a0976e45f48260d2a93c34aabb4230c42</anchor>
      <arglist>(ViSession vi, ViConstString filename, ViUInt32 cnt, ViPUInt32 retCnt)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viWrite</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a07c7b1ffd3c764360c7275ee615e28b4</anchor>
      <arglist>(ViSession vi, ViBuf buf, ViUInt32 cnt, ViPUInt32 retCnt)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viWriteAsync</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ae8d87eadd947c8fb1015b1b44c99ccc7</anchor>
      <arglist>(ViSession vi, ViBuf buf, ViUInt32 cnt, ViPJobId jobId)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viWriteFromFile</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad86c3d7c4aab058a0a5c014c0e0c6658</anchor>
      <arglist>(ViSession vi, ViConstString filename, ViUInt32 cnt, ViPUInt32 retCnt)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viAssertTrigger</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aaaf65b9637b232caecb746520805739b</anchor>
      <arglist>(ViSession vi, ViUInt16 protocol)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viReadSTB</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac9351f34c48ae75308fa7f666b5fac98</anchor>
      <arglist>(ViSession vi, ViPUInt16 status)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viClear</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a337fa2f73a1b5b46dbc53378a3842118</anchor>
      <arglist>(ViSession vi)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viSetBuf</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a13a400c8bc8158a2133f8b48d0c260bd</anchor>
      <arglist>(ViSession vi, ViUInt16 mask, ViUInt32 size)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viFlush</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a7b25ca66ba93154ae6d7dc8ea67f2b42</anchor>
      <arglist>(ViSession vi, ViUInt16 mask)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viBufWrite</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a07560d80dfbc33b070e511bb709b300b</anchor>
      <arglist>(ViSession vi, ViBuf buf, ViUInt32 cnt, ViPUInt32 retCnt)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viBufRead</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa42ca34d425ebe59e88d0dc4d698c409</anchor>
      <arglist>(ViSession vi, ViPBuf buf, ViUInt32 cnt, ViPUInt32 retCnt)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNCC</type>
      <name>viPrintf</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa2501234b47cbe550e0abc232b05e1a2</anchor>
      <arglist>(ViSession vi, ViString writeFmt,...)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viVPrintf</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>acc84a11dc22fa76d39ea424a97b7e61f</anchor>
      <arglist>(ViSession vi, ViString writeFmt, ViVAList params)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNCC</type>
      <name>viSPrintf</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>acc110afdc904284697f9a53d3e2f5b4b</anchor>
      <arglist>(ViSession vi, ViPBuf buf, ViString writeFmt,...)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viVSPrintf</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad7611de260bca08a35f502ec41e2747b</anchor>
      <arglist>(ViSession vi, ViPBuf buf, ViString writeFmt, ViVAList parms)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNCC</type>
      <name>viScanf</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>acb26b753b6cd37ebcc8db94e8e97ceee</anchor>
      <arglist>(ViSession vi, ViString readFmt,...)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viVScanf</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a172602f6271bd61273fa71ad5a598939</anchor>
      <arglist>(ViSession vi, ViString readFmt, ViVAList params)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNCC</type>
      <name>viSScanf</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad56d19917fbd882119208e093a07c6f4</anchor>
      <arglist>(ViSession vi, ViBuf buf, ViString readFmt,...)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viVSScanf</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>af9331513c630c60e51447f0da181127e</anchor>
      <arglist>(ViSession vi, ViBuf buf, ViString readFmt, ViVAList parms)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNCC</type>
      <name>viQueryf</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a6f83a78dd3ac9f8f8c26c098c5378923</anchor>
      <arglist>(ViSession vi, ViString writeFmt, ViString readFmt,...)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viVQueryf</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a2066d4279c9a5d40be32fd84b45b2473</anchor>
      <arglist>(ViSession vi, ViString writeFmt, ViString readFmt, ViVAList params)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viIn8</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a0045f9995314e431c7d06e55fa3d24ec</anchor>
      <arglist>(ViSession vi, ViUInt16 space, ViBusAddress offset, ViPUInt8 val8)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viOut8</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ac1bf62d16aaa8cb0f94a15a6b01035ee</anchor>
      <arglist>(ViSession vi, ViUInt16 space, ViBusAddress offset, ViUInt8 val8)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viIn16</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a23c3b3ff134961e6d3e9435ca77610a5</anchor>
      <arglist>(ViSession vi, ViUInt16 space, ViBusAddress offset, ViPUInt16 val16)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viOut16</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a20f9ea3b76df0ab6bc10b8fa5b11e89e</anchor>
      <arglist>(ViSession vi, ViUInt16 space, ViBusAddress offset, ViUInt16 val16)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viIn32</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a16563e89992b95e7a969eba0cbbe0275</anchor>
      <arglist>(ViSession vi, ViUInt16 space, ViBusAddress offset, ViPUInt32 val32)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viOut32</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aa4e41240b63864e3e155d1d8018f30d2</anchor>
      <arglist>(ViSession vi, ViUInt16 space, ViBusAddress offset, ViUInt32 val32)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viMoveIn8</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a7e79cfa80131e8f1ebf8757cfc450a80</anchor>
      <arglist>(ViSession vi, ViUInt16 space, ViBusAddress offset, ViBusSize length, ViAUInt8 buf8)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viMoveOut8</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a77ea8e82c9e5533391a0f98c496af68c</anchor>
      <arglist>(ViSession vi, ViUInt16 space, ViBusAddress offset, ViBusSize length, ViAUInt8 buf8)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viMoveIn16</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a9981bcb001f046374d79f9a962d26a21</anchor>
      <arglist>(ViSession vi, ViUInt16 space, ViBusAddress offset, ViBusSize length, ViAUInt16 buf16)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viMoveOut16</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a5e3330cb2cd63a8b780acae09865de27</anchor>
      <arglist>(ViSession vi, ViUInt16 space, ViBusAddress offset, ViBusSize length, ViAUInt16 buf16)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viMoveIn32</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a8460e438e0e0196c8f3b6d34420d0a68</anchor>
      <arglist>(ViSession vi, ViUInt16 space, ViBusAddress offset, ViBusSize length, ViAUInt32 buf32)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viMoveOut32</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a098ca22359fec10f6f71a90e49f47697</anchor>
      <arglist>(ViSession vi, ViUInt16 space, ViBusAddress offset, ViBusSize length, ViAUInt32 buf32)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viMove</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a32ef987175cfbc96e87b6bb2f58d57d1</anchor>
      <arglist>(ViSession vi, ViUInt16 srcSpace, ViBusAddress srcOffset, ViUInt16 srcWidth, ViUInt16 destSpace, ViBusAddress destOffset, ViUInt16 destWidth, ViBusSize srcLength)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viMoveAsync</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>afd6199b89e431bb75e3b09aaacf372fd</anchor>
      <arglist>(ViSession vi, ViUInt16 srcSpace, ViBusAddress srcOffset, ViUInt16 srcWidth, ViUInt16 destSpace, ViBusAddress destOffset, ViUInt16 destWidth, ViBusSize srcLength, ViPJobId jobId)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viMapAddress</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>afa391c7dc3b0875fb83069ebde7a8546</anchor>
      <arglist>(ViSession vi, ViUInt16 mapSpace, ViBusAddress mapOffset, ViBusSize mapSize, ViBoolean access, ViAddr suggested, ViPAddr address)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viUnmapAddress</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a4e032a1e47c46f020d237f8240e8ef78</anchor>
      <arglist>(ViSession vi)</arglist>
    </member>
    <member kind="function">
      <type>void _VI_FUNC</type>
      <name>viPeek8</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a209679bdcc663668bd96680272a95a61</anchor>
      <arglist>(ViSession vi, ViAddr address, ViPUInt8 val8)</arglist>
    </member>
    <member kind="function">
      <type>void _VI_FUNC</type>
      <name>viPoke8</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a5087bca756e704ef6e4aa8eebfc4beef</anchor>
      <arglist>(ViSession vi, ViAddr address, ViUInt8 val8)</arglist>
    </member>
    <member kind="function">
      <type>void _VI_FUNC</type>
      <name>viPeek16</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a8fc28b3d684fd2be64fadf647c54a6a7</anchor>
      <arglist>(ViSession vi, ViAddr address, ViPUInt16 val16)</arglist>
    </member>
    <member kind="function">
      <type>void _VI_FUNC</type>
      <name>viPoke16</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aca499a7a46b730a11f5604180678e6d6</anchor>
      <arglist>(ViSession vi, ViAddr address, ViUInt16 val16)</arglist>
    </member>
    <member kind="function">
      <type>void _VI_FUNC</type>
      <name>viPeek32</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab639c5af5e4875f95e16d913b57367f2</anchor>
      <arglist>(ViSession vi, ViAddr address, ViPUInt32 val32)</arglist>
    </member>
    <member kind="function">
      <type>void _VI_FUNC</type>
      <name>viPoke32</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>aca3a19994c815edc7510cb3842b3744b</anchor>
      <arglist>(ViSession vi, ViAddr address, ViUInt32 val32)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viMemAlloc</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a1fb648ad264f66cda7e794fb991fe18d</anchor>
      <arglist>(ViSession vi, ViBusSize size, ViPBusAddress offset)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viMemFree</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad487449e4f43a49ae67ffddcf07872e1</anchor>
      <arglist>(ViSession vi, ViBusAddress offset)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viGpibControlREN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a5316d8ee77405bd52be6c8abd5f84782</anchor>
      <arglist>(ViSession vi, ViUInt16 mode)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viGpibControlATN</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ae30efd6a911e16d9503e7f4499aa163a</anchor>
      <arglist>(ViSession vi, ViUInt16 mode)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viGpibSendIFC</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>afa3e78fccc1f1909020e9529a4aead55</anchor>
      <arglist>(ViSession vi)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viGpibCommand</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a77c75ddf4587ee43d653fb656a407baa</anchor>
      <arglist>(ViSession vi, ViBuf cmd, ViUInt32 cnt, ViPUInt32 retCnt)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viGpibPassControl</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a3aeb33b9b6278cef5e1ee1d249c4b2bb</anchor>
      <arglist>(ViSession vi, ViUInt16 primAddr, ViUInt16 secAddr)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viVxiCommandQuery</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a26f6e32e7101e431075d0f26fdf9096f</anchor>
      <arglist>(ViSession vi, ViUInt16 mode, ViUInt32 cmd, ViPUInt32 response)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viAssertUtilSignal</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ab6c70081f4c286b00371af8892c0bb57</anchor>
      <arglist>(ViSession vi, ViUInt16 line)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viAssertIntrSignal</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad38da1dd1d12d636124d60043f946e82</anchor>
      <arglist>(ViSession vi, ViInt16 mode, ViUInt32 statusID)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viMapTrigger</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a52a5f6f31e7b6b9a8567f743feeb585e</anchor>
      <arglist>(ViSession vi, ViInt16 trigSrc, ViInt16 trigDest, ViUInt16 mode)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viUnmapTrigger</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a0444e4e00abcc3bdbe05f8bfd4e5a2c8</anchor>
      <arglist>(ViSession vi, ViInt16 trigSrc, ViInt16 trigDest)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viUsbControlOut</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a37814d489bdb51a04841d42169e5c6cc</anchor>
      <arglist>(ViSession vi, ViInt16 bmRequestType, ViInt16 bRequest, ViUInt16 wValue, ViUInt16 wIndex, ViUInt16 wLength, ViBuf buf)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viUsbControlIn</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>ad6b67eff59877adcc21a92aaae8d8ebd</anchor>
      <arglist>(ViSession vi, ViInt16 bmRequestType, ViInt16 bRequest, ViUInt16 wValue, ViUInt16 wIndex, ViUInt16 wLength, ViPBuf buf, ViPUInt16 retCnt)</arglist>
    </member>
    <member kind="function">
      <type>ViStatus _VI_FUNC</type>
      <name>viVxiServantResponse</name>
      <anchorfile>visa_8h.html</anchorfile>
      <anchor>a69d173e287699def486eece5db267349</anchor>
      <arglist>(ViSession vi, ViInt16 mode, ViUInt32 resp)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>VisaBus.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Bus/Visa/</path>
    <filename>_visa_bus_8cpp</filename>
    <includes id="_visa_bus_8h" name="VisaBus.h" local="yes" imported="no">VisaBus.h</includes>
  </compound>
  <compound kind="file">
    <name>VisaBus.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Bus/Visa/</path>
    <filename>_visa_bus_8h</filename>
    <includes id="_generic_bus_8h" name="GenericBus.h" local="yes" imported="no">GenericBus.h</includes>
    <includes id="visa_8h" name="visa.h" local="yes" imported="no">visa.h</includes>
    <class kind="class">RsaToolbox::VisaBus</class>
    <namespace>RsaToolbox</namespace>
    <member kind="define">
      <type>#define</type>
      <name>FILENAME</name>
      <anchorfile>_visa_bus_8h.html</anchorfile>
      <anchor>a8de29f7c8bbf1a81cc6e71ac602032d3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>visatype.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Bus/Visa/</path>
    <filename>visatype_8h</filename>
    <member kind="define">
      <type>#define</type>
      <name>_VI_FAR</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a89fa79c79a1c430a41ec65dac263c2b9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_VI_FUNC</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a2a0992b192332494a0a59b464ca853b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_VI_FUNCC</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a537f7d3356a493d52efe6bbe936c0c5a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_VI_FUNCH</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a2a746f9c48a06ef512390f1cfb191e8d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_VI_SIGNED</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a3d9bb067d39e13cd9fd09c0f6a75a67f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_VI_ERROR</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>ac9eaef66513901c9972d4d222cc856c0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_VI_PTR</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a48d92e0f3ae0ca82892e6f8dceb31e8e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_VI_CONST_STRING_DEFINED</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a487723dbc6f7a1cca587b6a9c90fa876</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_SUCCESS</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a22e7e452a3213b64fa15c874a57c56a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_NULL</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>ae91dead03dd26f5cd33e48a5f6f04210</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_TRUE</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a88931333f0acad343b54a52381a1950f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VI_FALSE</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>acfa4bf9c418b40237f1e6825926645da</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VISAFN</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>af0a4b4bca14293c5d90adf2b9fdfe9c4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ViPtr</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a203443dea6ddaaf491ee4cf13fd1dd2c</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>unsigned long</type>
      <name>ViUInt32</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a267227b7d7e5e8b364101c8e4bf3595e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>_VI_SIGNED long</type>
      <name>ViInt32</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a1a7856e1fbcdeacfa08352ce9ba7e2a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViUInt32 _VI_PTR</type>
      <name>ViPUInt32</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a492f7114d54eb5b825277a961b5e1a3f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViUInt32 _VI_PTR</type>
      <name>ViAUInt32</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a5fe7db706d9b9f5be487c6507393625e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViInt32 _VI_PTR</type>
      <name>ViPInt32</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a75f40ceb67c13167ab0d5b585e94b705</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViInt32 _VI_PTR</type>
      <name>ViAInt32</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a0522cac5f36d8dff3142a782e7b80d2e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>unsigned short</type>
      <name>ViUInt16</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>ac0d155a8c2af89371278a47ed3e13930</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViUInt16 _VI_PTR</type>
      <name>ViPUInt16</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a576ead7567e1f5a4596b9d031fb4cdc8</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViUInt16 _VI_PTR</type>
      <name>ViAUInt16</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a0e4822de5efe8a76ff9e30ccf022742d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>_VI_SIGNED short</type>
      <name>ViInt16</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>ab9cbb12822b9038524324c392fac6b69</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViInt16 _VI_PTR</type>
      <name>ViPInt16</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>ad6a92196c67b08a92523023ad13197a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViInt16 _VI_PTR</type>
      <name>ViAInt16</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a0a342f630ac0b9da672f83edd90aa3d2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>unsigned char</type>
      <name>ViUInt8</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a14d890d0ccd79b0982798820371140fe</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViUInt8 _VI_PTR</type>
      <name>ViPUInt8</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>aa42e2315790781edf2bbae6795cbb722</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViUInt8 _VI_PTR</type>
      <name>ViAUInt8</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>aa4f17ea4ba2679aa32ba29daff5df3d4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>_VI_SIGNED char</type>
      <name>ViInt8</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>acb2655b77c535b1c3efe62b7a5106f88</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViInt8 _VI_PTR</type>
      <name>ViPInt8</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>ac674629bdf9f44d370100b9fbd1efa99</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViInt8 _VI_PTR</type>
      <name>ViAInt8</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a14d9fa61acd5d7c65bc5972fd1c879b1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>char</type>
      <name>ViChar</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>acb79646b9753a0e142a3266a1584a2b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViChar _VI_PTR</type>
      <name>ViPChar</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>ac98829caf61f372c728a1ac08b7ab44b</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViChar _VI_PTR</type>
      <name>ViAChar</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>ac946fac587d5da6b5f6e0671682268f9</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>unsigned char</type>
      <name>ViByte</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>aa7655e21a264b0c31e608b3e79502654</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViByte _VI_PTR</type>
      <name>ViPByte</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a0be6d03e6d2656338f8a7fba61f7762c</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViByte _VI_PTR</type>
      <name>ViAByte</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a9d05e8148c9e183b08bf7ae4286c1bf1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>void _VI_PTR</type>
      <name>ViAddr</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a911eccf8715049d633ea19b9d2c20bbd</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViAddr _VI_PTR</type>
      <name>ViPAddr</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a6d42dc5ad2b5b6a1eee810a2a70acd42</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViAddr _VI_PTR</type>
      <name>ViAAddr</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a720b22a827884b4b73b5aaa437949885</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>float</type>
      <name>ViReal32</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>ad1f7916df1ea7cf405e5a13c5a182f53</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViReal32 _VI_PTR</type>
      <name>ViPReal32</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a2fc393c14dde6b2e56e5143593465fff</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViReal32 _VI_PTR</type>
      <name>ViAReal32</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a9f0039df95d848ef51f434eef23c4d91</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>double</type>
      <name>ViReal64</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>ad96c7ae7f77c881f5774030e08e8ea76</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViReal64 _VI_PTR</type>
      <name>ViPReal64</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>ad0b304c61020d85659467c7c7868e090</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViReal64 _VI_PTR</type>
      <name>ViAReal64</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a43e8c7ceb1f9f8e9a1ea677068f58e27</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViPByte</type>
      <name>ViBuf</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a23bd41197b2ed6dbd855cf95448ecdd5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViPByte</type>
      <name>ViPBuf</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a59b15dc88d141c84559c25e0a81ac944</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViPByte _VI_PTR</type>
      <name>ViABuf</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a328eda2387ad904412a8c0a2146a37b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViPChar</type>
      <name>ViString</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>ab68c43ce62c02e290dcf3908e761d3e2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViPChar</type>
      <name>ViPString</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a661042c3019726e51ada346fe7fcba5c</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViPChar _VI_PTR</type>
      <name>ViAString</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>aa31e584014ed5df0b32ced7b07618f33</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViString</type>
      <name>ViRsrc</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a45e03b2097e03f8f14bb66eb5fd1a9ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViString</type>
      <name>ViPRsrc</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a5a45876acb94bd351a0a1a726734af97</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViString _VI_PTR</type>
      <name>ViARsrc</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a1de2ff41a01528c0947889ab15912893</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViUInt16</type>
      <name>ViBoolean</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a972164cd368c1cc9b3d37b0640c0f2bc</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViBoolean _VI_PTR</type>
      <name>ViPBoolean</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>ab906b4e3c45889128a69688c4bc5e180</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViBoolean _VI_PTR</type>
      <name>ViABoolean</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a36a71722a85800180c26cf550ae6e1ce</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViInt32</type>
      <name>ViStatus</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a871edadc0943077d5079a2172793f1af</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViStatus _VI_PTR</type>
      <name>ViPStatus</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a4f33027268dedb0d5cb5e7a54e0a3ac4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViStatus _VI_PTR</type>
      <name>ViAStatus</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>aa93e942c8733a1689184ee5fbca896b1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViUInt32</type>
      <name>ViVersion</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>ac269ce5479829c868d2aabda67f8a987</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViVersion _VI_PTR</type>
      <name>ViPVersion</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a6105a6189305985c9ab51fba0c422bbd</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViVersion _VI_PTR</type>
      <name>ViAVersion</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a8bf0debcbc79e56dc9fe41c704dc616e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViUInt32</type>
      <name>ViObject</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a7079f7efae4e7243f972a56e7d602f93</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViObject _VI_PTR</type>
      <name>ViPObject</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a9d5aa794bfd65d73b58b5c7a16a37de7</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViObject _VI_PTR</type>
      <name>ViAObject</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a1aa5d72a3e60feff99c725b594fcdb85</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViObject</type>
      <name>ViSession</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>af059dc8e4913a7191a27bd642123503d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViSession _VI_PTR</type>
      <name>ViPSession</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a7774ede71499acbff0760cb8b63d781b</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViSession _VI_PTR</type>
      <name>ViASession</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a983bfc9daf79493953d13e842327c2b1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ViUInt32</type>
      <name>ViAttr</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a7cd4a134fbd139f2192e86d1cd8d03bf</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>const ViChar *</type>
      <name>ViConstString</name>
      <anchorfile>visatype_8h.html</anchorfile>
      <anchor>a20d1d7ac6404d40272862894a1316dc0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Bus.dox</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Documentation/Pages/</path>
    <filename>_bus_8dox</filename>
  </compound>
  <compound kind="file">
    <name>Installer.dox</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Documentation/Pages/</path>
    <filename>_installer_8dox</filename>
  </compound>
  <compound kind="file">
    <name>Instrument.dox</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Documentation/Pages/</path>
    <filename>_instrument_8dox</filename>
  </compound>
  <compound kind="file">
    <name>Log.dox</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Documentation/Pages/</path>
    <filename>_log_8dox</filename>
  </compound>
  <compound kind="file">
    <name>MainPage.dox</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Documentation/Pages/</path>
    <filename>_main_page_8dox</filename>
  </compound>
  <compound kind="file">
    <name>PageOrder.dox</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Documentation/Pages/</path>
    <filename>_page_order_8dox</filename>
  </compound>
  <compound kind="file">
    <name>Templates.dox</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Documentation/Pages/</path>
    <filename>_templates_8dox</filename>
  </compound>
  <compound kind="file">
    <name>BalancedPort.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/General/</path>
    <filename>_balanced_port_8cpp</filename>
    <includes id="_balanced_port_8h" name="BalancedPort.h" local="yes" imported="no">BalancedPort.h</includes>
  </compound>
  <compound kind="file">
    <name>BalancedPort.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/General/</path>
    <filename>_balanced_port_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <class kind="class">RsaToolbox::BalancedPort</class>
    <namespace>RsaToolbox</namespace>
    <member kind="enumeration">
      <type></type>
      <name>BalancedPortType</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>acf1ebdd21871818fe315b47399550e12</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>SINGLE_ENDED</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>acf1ebdd21871818fe315b47399550e12aa5cea233f1879638f5a8eb18d6d87bd2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DIFFERENTIAL_MODE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>acf1ebdd21871818fe315b47399550e12ad1ac4eb333998510c340c1f9a78cff3f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>COMMON_MODE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>acf1ebdd21871818fe315b47399550e12a61c06effc644df0555d6f1a8cff5c83a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Connector.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/General/</path>
    <filename>_connector_8cpp</filename>
    <includes id="_connector_8h" name="Connector.h" local="yes" imported="no">Connector.h</includes>
  </compound>
  <compound kind="file">
    <name>Connector.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/General/</path>
    <filename>_connector_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <class kind="class">RsaToolbox::Connector</class>
    <namespace>RsaToolbox</namespace>
    <member kind="enumeration">
      <type></type>
      <name>ConnectorType</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>N_50_OHM_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6a61b16617c1ce5333d8c027318e8529fd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>N_75_OHM_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6a18904b59a1ded80dad70fa26ab7433ce</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>mm_7_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6aadf3cc24bafb07a62442c480f517b1fd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>mm_3_5_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6a4e914111258e64e9d4e2f0dbe3a2861e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>mm_2_92_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6a7d63e1ba4ae171f55faa48f6fbd1ee4b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>mm_2_4_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6ae5d22d314468dd08f9106c11c7788c40</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>mm_1_85_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6aab51064780378a3d667507fe8c99c4eb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>in_7_16_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6a820b27227c0cde3279db47be215854f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>TYPE_F_75_OHM_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6aba8a6d93ba5c67bec16f42bdf0f89db1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>BNC_50_OHM_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6ad8eb9947a41587a9b042b29f41a5b6e1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>BNC_75_OHM_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6a92016eee17a35da7bc24a7c67fdd31bb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>CUSTOM_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6ac9743d7b99ee46ae162cae020a155a2a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>UNKNOWN_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6a6a1586a3f010b4d1fa0be495c37c400f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>ConnectorGender</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a157ffe0e4dcd14784420ca337c6251a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>MALE_GENDER</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a157ffe0e4dcd14784420ca337c6251a1a9cfa23a30f4229b999a85cb0d577336a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>FEMALE_GENDER</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a157ffe0e4dcd14784420ca337c6251a1abc9baaf3a3a3b0b5eb7bdc25e1cac3de</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>NEUTRAL_GENDER</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a157ffe0e4dcd14784420ca337c6251a1a7faa7e6fb3376fa753cc5904fe40250e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Definitions.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/General/</path>
    <filename>_definitions_8h</filename>
    <namespace>RsaToolbox</namespace>
    <member kind="typedef">
      <type>std::complex&lt; double &gt;</type>
      <name>ComplexDouble</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ab82a545355b9d90ede8e612bf1bcb9ed</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; ComplexDouble &gt;</type>
      <name>ComplexRowVector</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aeff8cbc6faa565bb58d8f7467e117ae0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; ComplexRowVector &gt;</type>
      <name>ComplexMatrix2D</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aaf2b301924485eee4bed8606937522b6</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; ComplexMatrix2D &gt;</type>
      <name>ComplexMatrix3D</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a38e11e9315a74fce00f201a19143d587</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; double &gt;</type>
      <name>RowVector</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a377a6286f7e32baef3ecb46643772d71</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; RowVector &gt;</type>
      <name>Matrix2D</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4ac77922c110de258891e9f867b98a53</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; Matrix2D &gt;</type>
      <name>Matrix3D</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ba044817ed0459f04f0bc9e98f771c0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>QVector&lt; double &gt;</type>
      <name>QRowVector</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a277781f27cd64e7b4d0728b64ace87b8</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>QVector&lt; QRowVector &gt;</type>
      <name>QMatrix2D</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a3579c091e3c712a5242d147bc08b1762</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>QVector&lt; QMatrix2D &gt;</type>
      <name>QMatrix3D</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac184c78328efc65ad0e0f17890004fb7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>NetworkParameter</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa0ba4d0acd5fdf65863b14e183a9f1d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>S_PARAMETER</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa0ba4d0acd5fdf65863b14e183a9f1d8a83bb3bbd6a83a05fdbedc08fb53899fb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>Y_PARAMETER</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa0ba4d0acd5fdf65863b14e183a9f1d8a55de577f0f89545831b061382c6f97cf</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>Z_PARAMETER</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa0ba4d0acd5fdf65863b14e183a9f1d8abe9267f948ce9e69f2fea2fcee4f3a6f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>H_PARAMETER</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa0ba4d0acd5fdf65863b14e183a9f1d8afa76d9d5eddc128ea577e1a56aaa61c1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>G_PARAMETER</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa0ba4d0acd5fdf65863b14e183a9f1d8af616d0899e2406c6b505f1eaf9c1982d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>WaveQuantity</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad510ffc5b80ffa73e4165154fb790ef0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>A_WAVE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad510ffc5b80ffa73e4165154fb790ef0a3782fc4390ea544b078c2e11f8223f2c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>B_WAVE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad510ffc5b80ffa73e4165154fb790ef0aa86233ccbb7f4656d9f615f2e4a83dc5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>ReferenceLevel</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac2904dcef8205419855c49db4819d430</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RELATIVE_REFERENCE_LEVEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac2904dcef8205419855c49db4819d430a8d64deccd5f19fcee8b738285d325212</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ABSOLUTE_REFERENCE_LEVEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac2904dcef8205419855c49db4819d430a5abb6dfad5d133615e921ed3ff84d3f7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>TraceFormat</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a410a23bf00f6ac6aa86b91b31688806e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DB_MAGNITUDE_TRACE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a410a23bf00f6ac6aa86b91b31688806ea9d68efc32366135baa8c1c5e1b165f70</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>PHASE_DEG_TRACE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a410a23bf00f6ac6aa86b91b31688806ea3ec0bed6d4db74c6fcf94c68a0515ad9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>SMITH_CHART_TRACE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a410a23bf00f6ac6aa86b91b31688806eaf5132fcff918f839752b73ee3b10f880</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>POLAR_CHART_TRACE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a410a23bf00f6ac6aa86b91b31688806ea01f908e0790e62d02a879eeb09dc2823</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>VSWR_TRACE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a410a23bf00f6ac6aa86b91b31688806eaab675c23e794f71b66b3426a7118ccb0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>UNWRAP_PHASE_DEG_TRACE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a410a23bf00f6ac6aa86b91b31688806ea7b48bf464a21b7e8c0a95e0dead6f416</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>LINEAR_MAGNITUDE_TRACE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a410a23bf00f6ac6aa86b91b31688806ea5c7dc179b59b3b6e9bbd746bca718998</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>INVERSE_SMITH_CHART_TRACE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a410a23bf00f6ac6aa86b91b31688806ea5f3f338f813dd9e2c70b01af96eb4e13</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>REAL_PART_TRACE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a410a23bf00f6ac6aa86b91b31688806eac3a012c86fd1233de20b73b7bc05cd4b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>IMAGINARY_PART_TRACE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a410a23bf00f6ac6aa86b91b31688806eaaac708e187a6f005eb3925a7c1b5cd5f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DELAY_TRACE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a410a23bf00f6ac6aa86b91b31688806ea6c6bf22bb32e5758f4244b7adda0b8b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>CsvFormat</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afef9eb6dfe949b834d1b5b9d7e09d3ff</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>COMPLEX_DB_DEGREES_CSV</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afef9eb6dfe949b834d1b5b9d7e09d3ffa70dafe8e6d387e15403095e22242e536</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>COMPLEX_DB_RADIANS_CSV</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afef9eb6dfe949b834d1b5b9d7e09d3ffabcbae8db0109867d90d1587e730350fd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>COMPLEX_MAGNITUDE_DEGREES_CSV</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afef9eb6dfe949b834d1b5b9d7e09d3ffa7296e99e61aaec591a6defc0ae92dc4b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>COMPLEX_MAGNITUDE_RADIANS_CSV</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afef9eb6dfe949b834d1b5b9d7e09d3ffa045d8c588b42f9a6d6a581df9a18d56c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>COMPLEX_REAL_IMAGINARY_CSV</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afef9eb6dfe949b834d1b5b9d7e09d3ffa45f23fcf5d539cb4c309e022447acd51</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DECIBEL_MAGNITUDE_CSV</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afef9eb6dfe949b834d1b5b9d7e09d3ffa444a10677d50dbc91523a3377c5d9a90</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>MAGNITUDE_CSV</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afef9eb6dfe949b834d1b5b9d7e09d3ffa727b130c38095cde28e2a3624f6cf228</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>PHASE_DEGREES_CSV</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afef9eb6dfe949b834d1b5b9d7e09d3ffa09e5e4f652e0c6406919320dc1b534b3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>PHASE_RADIANS_CSV</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afef9eb6dfe949b834d1b5b9d7e09d3ffa65f4b2c5ca299bc0dcd2d722aec1b819</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>VSWR_CSV</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afef9eb6dfe949b834d1b5b9d7e09d3ffa27217d9450c80405548664c337e26ee4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>ComplexFormat</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a3fd1a9b25d76e60c5b6c4d86356986e9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DB_DEGREES_COMPLEX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a3fd1a9b25d76e60c5b6c4d86356986e9a925c3bdac31e15282640b1c5290ee62c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>MAGNITUDE_DEGREES_COMPLEX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a3fd1a9b25d76e60c5b6c4d86356986e9ac191a8ef9712fcb2ee164739bed9c025</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>REAL_IMAGINARY_COMPLEX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a3fd1a9b25d76e60c5b6c4d86356986e9a9c6c267b96c0f262fb37ed5ef2b21c7d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>Units</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac33d2b1fdba15c8bfb494f9cf0ef4190</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>NO_UNITS</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac33d2b1fdba15c8bfb494f9cf0ef4190a8c2ba6073467bd9d6ed60bd207a05096</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>SECONDS_UNITS</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac33d2b1fdba15c8bfb494f9cf0ef4190a34953c474698c4f3087532ed910169a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>HERTZ_UNITS</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac33d2b1fdba15c8bfb494f9cf0ef4190a24ebb6fb02d0d18316920fe75d4f1360</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RADIANS_UNITS</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac33d2b1fdba15c8bfb494f9cf0ef4190a788009337d13367c776b4c7a6e39ed93</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DEGREES_UNITS</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac33d2b1fdba15c8bfb494f9cf0ef4190a813b08eb76365a54ce935e4add28acab</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>OHMS_UNITS</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac33d2b1fdba15c8bfb494f9cf0ef4190a3f0e5aed9ad87d80aea38ee0139e9c29</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>SIEMENS_UNITS</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac33d2b1fdba15c8bfb494f9cf0ef4190ae756920478732860b23c6c1f3e6d3aac</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>WATTS_UNITS</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac33d2b1fdba15c8bfb494f9cf0ef4190af380a68b72c7642fdb9a1be1554a30ef</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DECIBELS_UNITS</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac33d2b1fdba15c8bfb494f9cf0ef4190a5159d6c3439081182324a3ac305c9bff</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DECIBEL_WATTS_UNITS</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac33d2b1fdba15c8bfb494f9cf0ef4190a8b519c16109d150640201f28c75bf91b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DECIBEL_MILLIWATTS_UNITS</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac33d2b1fdba15c8bfb494f9cf0ef4190aa8930c6544397269ee73b3ffbf82a84a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>SiPrefix</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9fb89ac56439ffc23c8e6942859ec3a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>TERA_PREFIX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9fb89ac56439ffc23c8e6942859ec3a6abd2b1d2aa49f93b8bb9585f83f830c18</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>GIGA_PREFIX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9fb89ac56439ffc23c8e6942859ec3a6a4dcaea62ac4bee447d5d5b0eeee87770</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>MEGA_PREFIX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9fb89ac56439ffc23c8e6942859ec3a6a1166811762516c7bf555accfd483d91d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>KILO_PREFIX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9fb89ac56439ffc23c8e6942859ec3a6a504c282f744bd1d83885ef547f9b6a19</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>NO_PREFIX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9fb89ac56439ffc23c8e6942859ec3a6ad8778d3390d2e20fcca92c8ef72a0903</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>MILLI_PREFIX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9fb89ac56439ffc23c8e6942859ec3a6ab7fe26f03d240b87584fe58c3adddd5e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>MICRO_PREFIX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9fb89ac56439ffc23c8e6942859ec3a6ac7dcf5de2e3b0e04a1ac04e68646b577</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>NANO_PREFIX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9fb89ac56439ffc23c8e6942859ec3a6a72d3a6356c1d49aa03a468f5405d95cb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>PICO_PREFIX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9fb89ac56439ffc23c8e6942859ec3a6a188b3047795515d3a4fb1b55efc90b7e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>FEMTO_PREFIX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9fb89ac56439ffc23c8e6942859ec3a6abcb0295886c8a661c7841bd1ce92c7aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const char</type>
      <name>RSA_TOOLBOX_VERSION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a3b0288a2b3aee0dfa13b36da65e5cfa5</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable">
      <type>const char</type>
      <name>COMPANY_FOLDER</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a84bb6c89cfb4eaf1f998b7ab9a92ab02</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable">
      <type>const double</type>
      <name>PI</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a952eac791b596a61bba0a133a3bb439f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const double</type>
      <name>E</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ab587ba72a9c23f238cb4fd70e2fdb545</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const double</type>
      <name>DBL_INF</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a62ba705fcc7c634064b60d0e973bb853</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const double</type>
      <name>DBL_NEG_INF</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7cf1a344b138cc337f4380711deba2f1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const double</type>
      <name>DBL_NAN</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad24e1f6ce807f3a5c245f7ee6e9e8b03</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>General.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/General/</path>
    <filename>_general_8cpp</filename>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <namespace>RsaToolbox</namespace>
    <member kind="function">
      <type>double</type>
      <name>bValue</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a42ad7834b66ba0f4eb681fa4168a6f8d</anchor>
      <arglist>(double x1, double y1, double x2, double y2)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>bValues</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a3f8487bbaf6e2ec148233a4d6576dae6</anchor>
      <arglist>(QRowVector x, QRowVector y)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>weightedAverage</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7d5e90c7a05fed784ef929a46d58ee98</anchor>
      <arglist>(QRowVector values, QRowVector weights)</arglist>
    </member>
    <member kind="function">
      <type>QDataStream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>_general_8cpp.html</anchorfile>
      <anchor>aeb50fe1f1675f29176810544dadd70ca</anchor>
      <arglist>(QDataStream &amp;stream, ComplexDouble value)</arglist>
    </member>
    <member kind="function">
      <type>QDataStream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>_general_8cpp.html</anchorfile>
      <anchor>a81faf08a5b2919c1053c0d8b644fbdd7</anchor>
      <arglist>(QDataStream &amp;stream, RsaToolbox::ComplexRowVector vector)</arglist>
    </member>
    <member kind="function">
      <type>QDataStream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>_general_8cpp.html</anchorfile>
      <anchor>a7b124830d985f584f3ecebfd1794864b</anchor>
      <arglist>(QDataStream &amp;stream, RsaToolbox::ComplexMatrix2D matrix)</arglist>
    </member>
    <member kind="function">
      <type>QDataStream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>_general_8cpp.html</anchorfile>
      <anchor>a1429553fa5c7161976a710e5d5beccc3</anchor>
      <arglist>(QDataStream &amp;stream, RsaToolbox::ComplexMatrix3D matrix)</arglist>
    </member>
    <member kind="function">
      <type>QDataStream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>_general_8cpp.html</anchorfile>
      <anchor>ad09e87ebcb2ad244fd704e7a473fb074</anchor>
      <arglist>(QDataStream &amp;stream, ComplexDouble &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>QDataStream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>_general_8cpp.html</anchorfile>
      <anchor>aec5b5e6bc3d4d0b54f0db49f142f667c</anchor>
      <arglist>(QDataStream &amp;stream, RsaToolbox::ComplexRowVector &amp;vector)</arglist>
    </member>
    <member kind="function">
      <type>QDataStream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>_general_8cpp.html</anchorfile>
      <anchor>a952a5cbbb79ce1ead8cd8dd439fdcbca</anchor>
      <arglist>(QDataStream &amp;stream, RsaToolbox::ComplexMatrix2D &amp;matrix)</arglist>
    </member>
    <member kind="function">
      <type>QDataStream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>_general_8cpp.html</anchorfile>
      <anchor>a142433dd0bf51185b4d8543702330c3c</anchor>
      <arglist>(QDataStream &amp;stream, RsaToolbox::ComplexMatrix3D &amp;matrix)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>General.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/General/</path>
    <filename>_general_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <namespace>RsaToolbox</namespace>
    <member kind="function">
      <type>double</type>
      <name>toDouble</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a5e75a474c2f8ba5242fce4450dcce623</anchor>
      <arglist>(SiPrefix prefix)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>acbf9cedf585f787735a12fb954f32f84</anchor>
      <arglist>(ComplexFormat format)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a401f7fe87f90c5ca198323624136aad1</anchor>
      <arglist>(NetworkParameter parameter)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a2fbaebec0acf687c84979be06d132207</anchor>
      <arglist>(NetworkParameter parameter, uint outputPort, uint inputPort)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a91578283cbe5524cd256ae631d7614e5</anchor>
      <arglist>(SiPrefix prefix)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a2b7097a8be97e531c5cffc1ec66b8f8a</anchor>
      <arglist>(Units units)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>abddef2d0ac592f2c9bd33cdbb2f70549</anchor>
      <arglist>(SiPrefix prefix, Units units)</arglist>
    </member>
    <member kind="function">
      <type>SiPrefix</type>
      <name>toSiPrefix</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aef3265ac085cb4b9c3123482a618dc6d</anchor>
      <arglist>(QString prefix)</arglist>
    </member>
    <member kind="function">
      <type>SiPrefix</type>
      <name>getPrefix</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1f7da27811bba5dc59af9872c72b5238</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>AppendPath</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa5cb97be2bab893b0072136464fbbf23</anchor>
      <arglist>(QDir path, QString filename)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>AppendCurrentDirectory</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a56aa4142e468fd8422c87332b23a297f</anchor>
      <arglist>(QString filename)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>GetAppDataPath</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>af57d5ee3608f72345359f9fe53e65e66</anchor>
      <arglist>(QString program_folder)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>AppendAppDataPath</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a05cc3717c6e3f03bb1cc84fae5b3a053</anchor>
      <arglist>(QString program_folder, QString filename)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toScientificNotation</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>af1a4280bf5e6d3cba3f29e11cfad6772</anchor>
      <arglist>(double value, int decimal_places, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>formatValue</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a78777ebbbe7e2f270250983693a54f57</anchor>
      <arglist>(double value, int decimal_places, Units units, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>formatDouble</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4f6310dc021758e8f2015b3e50d26591</anchor>
      <arglist>(double value, int decimal_places)</arglist>
    </member>
    <member kind="function">
      <type>QStringList</type>
      <name>toStringList</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a43e55b9319f66b66baaa2f8841e999f7</anchor>
      <arglist>(QVector&lt; T &gt; vector)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1ff4b93281f6f785d0636ec89688d423</anchor>
      <arglist>(QVector&lt; T &gt; vector, QString separator)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4c251188f7653030333b2dbca1bafe2d</anchor>
      <arglist>(QStringList list, QString separator)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a367a66470f1261677697344ca31223b0</anchor>
      <arglist>(ComplexRowVector vector, QString list_separator, QString format=&quot;(%1, %2)&quot;)</arglist>
    </member>
    <member kind="function">
      <type>QStringList</type>
      <name>portLabels</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac8b87f32bdc28e2626225c2e2f1320aa</anchor>
      <arglist>(QVector&lt; uint &gt; ports)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>portString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a59270a806ff441a388b4abf455af0e6d</anchor>
      <arglist>(QVector&lt; uint &gt; ports)</arglist>
    </member>
    <member kind="function">
      <type>QStringList</type>
      <name>channelLabels</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa3b8d08858b7f4cb6f24de1c124a94eb</anchor>
      <arglist>(QVector&lt; uint &gt; channels)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; uint &gt;</type>
      <name>parseUints</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>abb3ddaa4e84753ac45836e592feb3e93</anchor>
      <arglist>(QString values, QString separator, QString ignore=&quot;&quot;)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; int &gt;</type>
      <name>parseInts</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a8c6a37d918959daf948d92f5957c4b6b</anchor>
      <arglist>(QString values, QString separator, QString ignore=&quot;&quot;)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>parseDoubles</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a97ba76e16afd9853c7a81a6300db5cbe</anchor>
      <arglist>(QString values, QString separator, QString ignore=&quot;&quot;)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>parseComplex</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ab6a9bd540b8f1e2e4ea5bc7e08b4f01b</anchor>
      <arglist>(QString values, QString separator, QString ignore=&quot;&quot;)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>parseComplex</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a257ef823691cebf05e5b8f223b5d9b0b</anchor>
      <arglist>(QRowVector values)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>parseQRowVector</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1d3d8cb2376dd1beb46014ac96b59b60</anchor>
      <arglist>(QString buffer)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>parseQRowVector</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a0f00ddf7ecf4d2c63237fc41036fa7db</anchor>
      <arglist>(ComplexRowVector values)</arglist>
    </member>
    <member kind="function">
      <type>QByteArray</type>
      <name>toBlockDataFormat</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a74dbc88890beeca8ae8c7b2bb5840737</anchor>
      <arglist>(QRowVector values)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>toQRowVector</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7ac15524e43d1d695ecd4adbeb9bd242</anchor>
      <arglist>(QByteArray blockData)</arglist>
    </member>
    <member kind="function">
      <type>QByteArray</type>
      <name>toBlockDataFormat</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4c977f59cee987da721313140ff98d09</anchor>
      <arglist>(ComplexRowVector values)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>toComplexRowVector</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a095d2fe4ee83260c30082bb62657eeb8</anchor>
      <arglist>(QByteArray blockData)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>toDb</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a90325e3eee0931db9b03e33bd969e1ba</anchor>
      <arglist>(double magnitude)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>toDb</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a8b5fac37bd7f5d387e1fbaed38da99b6</anchor>
      <arglist>(QRowVector magnitudes)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>toDb</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aed23023feacd7e66ba8f332cd73a929a</anchor>
      <arglist>(ComplexDouble complexValue)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>toDb</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1d980b57236be3867233edbeca770a9e</anchor>
      <arglist>(ComplexRowVector complexValues)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>toMagnitude</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7a6ebb9f84519ca70bfdcd06a5c6e6cf</anchor>
      <arglist>(double decibels)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>toMagnitude</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a12f7bf7c929558a1234d5d92981059b6</anchor>
      <arglist>(ComplexDouble complexValue)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>toMagnitude</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a85bc362fbb015bcc9d7f4dee551f3ae6</anchor>
      <arglist>(QRowVector values_dB)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>toMagnitude</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac3bb953d5466cb4eb121671c6e5f965b</anchor>
      <arglist>(ComplexRowVector complexValues)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>degrees</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac2ee607bb77fc38d0a66d81a561d2c82</anchor>
      <arglist>(double phase_rad)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>degrees</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad9fad2c39c10c26ee64a498425585e0a</anchor>
      <arglist>(QRowVector phases_rad)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>angle_deg</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a16ffbeaf48af6a84d250a4b6ed08cfbf</anchor>
      <arglist>(ComplexDouble complexValue)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>angle_deg</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac4a1f133e1ad088653bf76c1cffbd8a4</anchor>
      <arglist>(ComplexRowVector complexValues)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>radians</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a43ada3b27897583fde5a568906a41c0c</anchor>
      <arglist>(double phase_deg)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>radians</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a57f7b6fdcaf0ee08f50bd5d6cef201b3</anchor>
      <arglist>(QRowVector phases_deg)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>angle_rad</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aeb448e4e152415694b361688b51757fe</anchor>
      <arglist>(ComplexDouble complexValue)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>angle_rad</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a36d93e3f76c6602b9959bb5171486b70</anchor>
      <arglist>(ComplexRowVector complexValues)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>toVswr</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ae59989515f7fd67a3d5b0988a7325a14</anchor>
      <arglist>(double magnitude)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>toVswr</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1a9c7d9d7aa4cffa3fd95574d23981f8</anchor>
      <arglist>(QRowVector magnitudes)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>toVswr</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a100fb849363ad7d9b7df0e2c31de544a</anchor>
      <arglist>(ComplexDouble complexValue)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>toVswr</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afe11daae4102f507f083c07b47d44b63</anchor>
      <arglist>(ComplexRowVector complexValues)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>real</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad8addfeea470bb836f4ccdbbe5457e9f</anchor>
      <arglist>(ComplexRowVector complexValues)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>imaginary</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a8aa532707d4fbf883ce23b23b895846b</anchor>
      <arglist>(ComplexRowVector complexValues)</arglist>
    </member>
    <member kind="function">
      <type>ComplexDouble</type>
      <name>fromRealImag</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a5f96f507a98b20424a6d5f0f077935b5</anchor>
      <arglist>(double real, double imag)</arglist>
    </member>
    <member kind="function">
      <type>ComplexDouble</type>
      <name>fromMagDegrees</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a2910b66fdecb1db3c45def9b20416ffa</anchor>
      <arglist>(double magnitude, double angle_deg)</arglist>
    </member>
    <member kind="function">
      <type>ComplexDouble</type>
      <name>fromDbDegrees</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4051a16c1fec914796d0e1c033216ed2</anchor>
      <arglist>(double dB, double angle_deg)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; int &gt;</type>
      <name>range</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9f9040fbb1ba563ada8f3e293fcb325d</anchor>
      <arglist>(int start, int stop, int stepSize=1)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; uint &gt;</type>
      <name>range</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aba29c509dc659952d0784be2653e58ad</anchor>
      <arglist>(uint start, uint stop, uint stepSize=1)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>linearSpacing</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa06a5b0c1beff543070e85ef69cfca1c</anchor>
      <arglist>(double start, double stop, int points)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>linearSpacing</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a62a922faa3d1fa360e6c10c5834ab6b1</anchor>
      <arglist>(QRowVector &amp;result, double start, double stop, int points)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>linearSpacing</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>acb477457f800e6528ebe51e7b77388f9</anchor>
      <arglist>(RowVector &amp;result, double start, double stop, int points)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logSpacing</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa6a6dc53ed0a3aeb7b13422f48a792c3</anchor>
      <arglist>(QRowVector &amp;result, double start, double stop, int points)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isInfinity</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a82d846558217ee9aa87a8fe9fb74024a</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotInfinity</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a5b2f17251e538bec30ab06a564e54be3</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNaN</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a2da3316cdc0d9f30d9b7c19e796191da</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotNaN</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>adbed0f7d690e0553b77c42fd0e3960bf</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>roundInf</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a82406f77f81e29888d7c1d0fc6cb90c3</anchor>
      <arglist>(double value, double toValue=DBL_MAX)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>roundInf</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1609c2b05d77afbc01574aa730802758</anchor>
      <arglist>(QRowVector values, double toValue=DBL_MAX)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>round</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ab064c7a47b8e780e57f6df879cf16076</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>round</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>abfb90b6522dc506a85602ab8ecd47270</anchor>
      <arglist>(double value, uint decimal_places)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>floor</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac10aef7f1e85aca6030e5eeec0e5e1d4</anchor>
      <arglist>(double value, double interval)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>ceiling</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a01171a0778b6254c6e4484061c2447ff</anchor>
      <arglist>(double value, double interval)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>roundAxis</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afb5aace1130c30638a96cf43ad35db87</anchor>
      <arglist>(double min, double max, double interval, double &amp;axis_min, double &amp;axis_max)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>roundAxis</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ae9aac1d46b78292370d33f0a73891042</anchor>
      <arglist>(QRowVector values, double interval, double &amp;axis_min, double &amp;axis_max)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>roundAxis</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a74089e52a82669ed232297f52369b532</anchor>
      <arglist>(RowVector values, double interval, double &amp;axis_min, double &amp;axis_max)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>linearInterpolateX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aea56743d85a9d5f085a61d121659a0fd</anchor>
      <arglist>(double x1, double y1, double x2, double y2, double y_desired)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>linearInterpolateY</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a12bd990ca41ec3647a7c1b183cebed50</anchor>
      <arglist>(double x1, double y1, double x2, double y2, double x_desired)</arglist>
    </member>
    <member kind="function">
      <type>ComplexDouble</type>
      <name>linearInterpolateY</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ab643f9391face07b2757327ced1ec1b5</anchor>
      <arglist>(double x1, ComplexDouble y1, double x2, ComplexDouble y2, double x_desired)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>exp</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa4c85985ac0b1e775a67cb80a5d91029</anchor>
      <arglist>(ComplexRowVector x)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>sum</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1bc51eb7992dcfc1a84d5b70b80e754c</anchor>
      <arglist>(QRowVector x)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>diff</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aac3484c9070dd5a7491e6a31ffe755d1</anchor>
      <arglist>(QRowVector x)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>mod</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aaa0a9a7f90355c93c633892b791f954d</anchor>
      <arglist>(QRowVector x, double denominator)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>cumulativeSum</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a158966986ea84b4b72674ee0b7888be7</anchor>
      <arglist>(QRowVector x)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>arg</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a283f78093d2c8cdc8f295f5391228250</anchor>
      <arglist>(ComplexRowVector x)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>wrap</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1de101bc43524b31d4b99d056796a79f</anchor>
      <arglist>(double x, double bounds=2.0 *PI)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>wrap</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa963d727897de9ddf14b8c64a7946da0</anchor>
      <arglist>(QRowVector x, double bounds=2.0 *PI)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>unwrap</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a48bc89f06f044b86c3cb890b5a565090</anchor>
      <arglist>(QRowVector x, double bounds=2.0 *PI)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>phaseAtDc_rad</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a2cbe6bcaeb53d68b19eca6f9166359e1</anchor>
      <arglist>(QRowVector x, ComplexRowVector y)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>phaseAtDc_deg</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad9627b876d217d16ba9fa9529fc0deae</anchor>
      <arglist>(QRowVector x, ComplexRowVector y)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>fixPhaseAtDc</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7f069a567159a5a555ce74de827e7f61</anchor>
      <arglist>(QRowVector x, ComplexRowVector y)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>addPropagate</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a36dfd672c3e5e7469627e20af0297424</anchor>
      <arglist>(QRowVector x, int startIndex, double value)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>subtractPropagate</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aab674d0683402508336c09eee11263ba</anchor>
      <arglist>(QRowVector x, int startIndex, double value)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>sqrt</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a108ee276905f6053f18adbdd8c4f1bf7</anchor>
      <arglist>(ComplexRowVector x)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>smoothSqrt</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a34accb03cadb6e22e40e87bd033d447f</anchor>
      <arglist>(ComplexRowVector x)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>smoothPhase</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad35bef2369fdf259206c950568378ff9</anchor>
      <arglist>(ComplexRowVector x)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>conjugate</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a32cbf8a3eea06963782d7c82490838a5</anchor>
      <arglist>(ComplexRowVector x)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>multiply</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a44eb6477e388c2a28053326b8f4c4cc1</anchor>
      <arglist>(ComplexRowVector vector, double scalar)</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix2D</type>
      <name>multiply</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>adf5a3ca95570a11e958c6a487550717b</anchor>
      <arglist>(ComplexMatrix2D matrix, double scalar)</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix3D</type>
      <name>multiply</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>abcd3107aa8f1ceed0ca6ec2207861be7</anchor>
      <arglist>(ComplexMatrix3D matrix, double scalar)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>multiply</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a93fdb05e9ed1fae791ef170ea3a9e1a9</anchor>
      <arglist>(QRowVector vector, ComplexDouble scalar)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>multiply</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a2bc8edeadc8825a1356d4be9eac1dd67</anchor>
      <arglist>(ComplexRowVector vector, ComplexDouble scalar)</arglist>
    </member>
    <member kind="function">
      <type>RowVector</type>
      <name>multiply</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a39d6fdfe572189b4b543ed2c1fe68add</anchor>
      <arglist>(RowVector vector, double scalar)</arglist>
    </member>
    <member kind="function">
      <type>Matrix2D</type>
      <name>multiply</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aff7d9037a1da9d6b6e7e8c23ed9ebf8a</anchor>
      <arglist>(Matrix2D matrix, double scalar)</arglist>
    </member>
    <member kind="function">
      <type>Matrix3D</type>
      <name>multiply</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>acf02aaac2d28bfcc353b1056b92a20b0</anchor>
      <arglist>(Matrix3D matrix, double scalar)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>multiply</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ab83b504dfc81911d54b73beedc2d5fc3</anchor>
      <arglist>(QRowVector vector, double scalar)</arglist>
    </member>
    <member kind="function">
      <type>QMatrix2D</type>
      <name>multiply</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>acbab33a3bf448153fd77fae10488d89d</anchor>
      <arglist>(QMatrix2D matrix, double scalar)</arglist>
    </member>
    <member kind="function">
      <type>QMatrix3D</type>
      <name>multiply</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a24a3db61cb4b64929a539fc03679195a</anchor>
      <arglist>(QMatrix3D matrix, double scalar)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>multiplyEach</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>adac5ac068e0edcddc335500c81a65748</anchor>
      <arglist>(ComplexRowVector vector1, ComplexRowVector vector2)</arglist>
    </member>
    <member kind="function">
      <type>RowVector</type>
      <name>multiplyEach</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a64e958fd26a01aeabc5568afb033929e</anchor>
      <arglist>(RowVector vector1, RowVector vector2)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>multiplyEach</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a61eafc7a6dae31957c61dfd2836f1287</anchor>
      <arglist>(QRowVector vector1, QRowVector vector2)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>divideEach</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac9649d420706cacda486e6a326b7905b</anchor>
      <arglist>(ComplexRowVector vector1, ComplexRowVector vector2)</arglist>
    </member>
    <member kind="function">
      <type>RowVector</type>
      <name>divideEach</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac6ccb7bd8170214ee3dcc998f42e3db9</anchor>
      <arglist>(RowVector vector1, RowVector vector2)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>divideEach</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a0ada20a8cc8f6b2d1d68ff3ca6b1edbe</anchor>
      <arglist>(QRowVector vector1, QRowVector vector2)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>add</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7eb1bec04e0160d1490483197bfd8bd6</anchor>
      <arglist>(ComplexRowVector vector1, ComplexRowVector vector2)</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix2D</type>
      <name>add</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aeb70d9906255b09caff1fa71426d6646</anchor>
      <arglist>(ComplexMatrix2D matrix1, ComplexMatrix2D matrix2)</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix3D</type>
      <name>add</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7407b694c1bf322461d45217e204b6b8</anchor>
      <arglist>(ComplexMatrix3D matrix1, ComplexMatrix3D matrix2)</arglist>
    </member>
    <member kind="function">
      <type>RowVector</type>
      <name>add</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a73a78c0fecff5f804b088e9fc5b286a3</anchor>
      <arglist>(RowVector vector1, RowVector vector2)</arglist>
    </member>
    <member kind="function">
      <type>Matrix2D</type>
      <name>add</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac5382071b09bfe5f4bfd6ea42e9f22b0</anchor>
      <arglist>(Matrix2D matrix1, Matrix2D matrix2)</arglist>
    </member>
    <member kind="function">
      <type>Matrix3D</type>
      <name>add</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a31ebf455c15012c311764d743c9e13ec</anchor>
      <arglist>(Matrix3D matrix1, Matrix3D matrix2)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>add</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad19951063015f44edd32dc0013d94cd6</anchor>
      <arglist>(QRowVector vector1, QRowVector vector2)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>add</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1908c3a1b75a5b5c646690cc3fdf4fbc</anchor>
      <arglist>(QRowVector vector, double scalar)</arglist>
    </member>
    <member kind="function">
      <type>QMatrix2D</type>
      <name>add</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a184fe3cc09fc3b4b1418541dfd4e39cf</anchor>
      <arglist>(QMatrix2D matrix1, QMatrix2D matrix2)</arglist>
    </member>
    <member kind="function">
      <type>QMatrix3D</type>
      <name>add</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa8aa4c9635844b040a44c9854c59bbd7</anchor>
      <arglist>(QMatrix3D matrix1, QMatrix3D matrix2)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>subtract</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>af48500405f7d606c8fadfb35a0ddcec2</anchor>
      <arglist>(ComplexRowVector vector1, ComplexRowVector vector2)</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix2D</type>
      <name>subtract</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a84cef2594a805379baa8e0a1df395dc7</anchor>
      <arglist>(ComplexMatrix2D matrix1, ComplexMatrix2D matrix2)</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix3D</type>
      <name>subtract</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad5815ea51d583aed736472f8627df0c6</anchor>
      <arglist>(ComplexMatrix3D matrix1, ComplexMatrix3D matrix2)</arglist>
    </member>
    <member kind="function">
      <type>RowVector</type>
      <name>subtract</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9a20fcbf652da781fb2fcbbf53e148e8</anchor>
      <arglist>(RowVector vector1, RowVector vector2)</arglist>
    </member>
    <member kind="function">
      <type>Matrix2D</type>
      <name>subtract</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a3a863d164af0e3584db698426bfb0869</anchor>
      <arglist>(Matrix2D matrix1, Matrix2D matrix2)</arglist>
    </member>
    <member kind="function">
      <type>Matrix3D</type>
      <name>subtract</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>af7805c05bdb953b4da6f59a119a802fd</anchor>
      <arglist>(Matrix3D matrix1, Matrix3D matrix2)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>subtract</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>af7ac924bb672e7342c7ba765a39be0f4</anchor>
      <arglist>(QRowVector vector1, QRowVector vector2)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>subtract</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a64bce15fdbba4d707f489d44361234cc</anchor>
      <arglist>(QRowVector vector, double scalar)</arglist>
    </member>
    <member kind="function">
      <type>QMatrix2D</type>
      <name>subtract</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a39f0d94b234b9a99349de41f2b9b74ff</anchor>
      <arglist>(QMatrix2D matrix1, QMatrix2D matrix2)</arglist>
    </member>
    <member kind="function">
      <type>QMatrix3D</type>
      <name>subtract</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a742556b11d5fc4792c002d709cc492fd</anchor>
      <arglist>(QMatrix3D matrix1, QMatrix3D matrix2)</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix2D</type>
      <name>transpose</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aeae8c8fe3a4b7f4451bd51373b6262d6</anchor>
      <arglist>(ComplexMatrix2D matrix)</arglist>
    </member>
    <member kind="function">
      <type>QMatrix2D</type>
      <name>transpose</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aebb27cbadbdfe5fb7ee8a7d904bd592c</anchor>
      <arglist>(QMatrix2D matrix)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>resize</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a6ca04a2d097b31b51db036f57ebba68e</anchor>
      <arglist>(ComplexMatrix2D &amp;matrix, uint rows, uint columns)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>resize</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ab2a8b1446250d8482ca08018f503cfc8</anchor>
      <arglist>(ComplexMatrix3D &amp;matrix, uint dimension1, uint dimension2, uint dimension3)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>serialize</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad52c99a5bd3de773d0b6a6520885f667</anchor>
      <arglist>(ComplexMatrix2D const &amp;matrix)</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix2D</type>
      <name>toComplexMatrix2D</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4b88ff0464ec91ec2b6f53714b1fb8d3</anchor>
      <arglist>(ComplexRowVector const &amp;data, uint rows, uint columns)</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix3D</type>
      <name>toComplexMatrix3D</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a810f041d7d3c1e797b4e6040fe1f6b82</anchor>
      <arglist>(ComplexRowVector const &amp;data, uint dimension1, uint dimension2, uint dimension3)</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix2D</type>
      <name>subsection</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1e8fd01296b09562665ef20f0076c261</anchor>
      <arglist>(ComplexMatrix2D matrix, QVector&lt; uint &gt; rows, QVector&lt; uint &gt; columns)</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix2D</type>
      <name>subsection</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>abae34756352c3e78039a1d936b73e681</anchor>
      <arglist>(ComplexMatrix2D matrix, QVector&lt; uint &gt; indices)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>af1cf69015287759252f8b7e76a326a64</anchor>
      <arglist>(ComplexMatrix2D &amp;matrix, ComplexMatrix2D data, QVector&lt; uint &gt; toRows, QVector&lt; uint &gt; toColumns)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4a82ae7a3e94a94cdae2b3ecd4a80faa</anchor>
      <arglist>(ComplexMatrix2D &amp;matrix, ComplexMatrix2D data, QVector&lt; uint &gt; indices)</arglist>
    </member>
    <member kind="function">
      <type>QMap&lt; T, V &gt;</type>
      <name>cascade</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad53aceeae099578a31d8bd374328d505</anchor>
      <arglist>(QMap&lt; T, U &gt; a, QMap&lt; U, V &gt; b)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>max</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a2daa770aac6dd9e2682dcbd091b3a900</anchor>
      <arglist>(QVector&lt; T &gt; vector)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>max</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a092585c3ac51be4fd2f5890a4f39f797</anchor>
      <arglist>(QVector&lt; T &gt; vector, T &amp;maximum, int &amp;index)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>max</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a14051d4d2caf61e4ff147cdb70e8e49f</anchor>
      <arglist>(std::vector&lt; T &gt; vector)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>max</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a8e90b240b35e29198e213b4f13149b11</anchor>
      <arglist>(std::vector&lt; T &gt; vector, T &amp;maximum, int &amp;index)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>min</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aea9801959ad0df2547ebd0e7e2717c5b</anchor>
      <arglist>(QVector&lt; T &gt; vector)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>min</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aaeab31f23497d4c7f2fb108afbd5e6f8</anchor>
      <arglist>(QVector&lt; T &gt; vector, T &amp;minimum, int &amp;index)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>min</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a388df8a3bb95fba9ed7ff312be73237d</anchor>
      <arglist>(std::vector&lt; T &gt; vector)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>min</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1e635f140e9a3d386a8ae68d4183ee23</anchor>
      <arglist>(std::vector&lt; T &gt; vector, T &amp;minimum, int &amp;index)</arglist>
    </member>
    <member kind="function">
      <type>QDataStream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>_general_8h.html</anchorfile>
      <anchor>a23e919e3d2c278924e9ef35075ded3e9</anchor>
      <arglist>(QDataStream &amp;stream, RsaToolbox::ComplexDouble value)</arglist>
    </member>
    <member kind="function">
      <type>QDataStream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>_general_8h.html</anchorfile>
      <anchor>a81faf08a5b2919c1053c0d8b644fbdd7</anchor>
      <arglist>(QDataStream &amp;stream, RsaToolbox::ComplexRowVector vector)</arglist>
    </member>
    <member kind="function">
      <type>QDataStream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>_general_8h.html</anchorfile>
      <anchor>a7b124830d985f584f3ecebfd1794864b</anchor>
      <arglist>(QDataStream &amp;stream, RsaToolbox::ComplexMatrix2D matrix)</arglist>
    </member>
    <member kind="function">
      <type>QDataStream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>_general_8h.html</anchorfile>
      <anchor>a1429553fa5c7161976a710e5d5beccc3</anchor>
      <arglist>(QDataStream &amp;stream, RsaToolbox::ComplexMatrix3D matrix)</arglist>
    </member>
    <member kind="function">
      <type>QDataStream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>_general_8h.html</anchorfile>
      <anchor>ac357e579138bc58ffdb054b303c5420b</anchor>
      <arglist>(QDataStream &amp;stream, RsaToolbox::ComplexDouble &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>QDataStream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>_general_8h.html</anchorfile>
      <anchor>aec5b5e6bc3d4d0b54f0db49f142f667c</anchor>
      <arglist>(QDataStream &amp;stream, RsaToolbox::ComplexRowVector &amp;vector)</arglist>
    </member>
    <member kind="function">
      <type>QDataStream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>_general_8h.html</anchorfile>
      <anchor>a952a5cbbb79ce1ead8cd8dd439fdcbca</anchor>
      <arglist>(QDataStream &amp;stream, RsaToolbox::ComplexMatrix2D &amp;matrix)</arglist>
    </member>
    <member kind="function">
      <type>QDataStream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>_general_8h.html</anchorfile>
      <anchor>a142433dd0bf51185b4d8543702330c3c</anchor>
      <arglist>(QDataStream &amp;stream, RsaToolbox::ComplexMatrix3D &amp;matrix)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>IndexName.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/General/</path>
    <filename>_index_name_8cpp</filename>
    <includes id="_index_name_8h" name="IndexName.h" local="yes" imported="no">IndexName.h</includes>
  </compound>
  <compound kind="file">
    <name>IndexName.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/General/</path>
    <filename>_index_name_8h</filename>
    <class kind="class">RsaToolbox::IndexName</class>
    <namespace>RsaToolbox</namespace>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a6187f001c2d47a1bcf7e55fffc3cae75</anchor>
      <arglist>(const IndexName &amp;right, const IndexName &amp;left)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ada8e824ea3f432f40148ecb9848c3ca6</anchor>
      <arglist>(const IndexName &amp;right, const IndexName &amp;left)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Key.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/General/</path>
    <filename>_key_8h</filename>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <class kind="class">RsaToolbox::Key</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>NameLabel.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/General/</path>
    <filename>_name_label_8cpp</filename>
    <includes id="_name_label_8h" name="NameLabel.h" local="yes" imported="no">NameLabel.h</includes>
  </compound>
  <compound kind="file">
    <name>NameLabel.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/General/</path>
    <filename>_name_label_8h</filename>
    <class kind="class">RsaToolbox::NameLabel</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>NetworkData.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/General/</path>
    <filename>_network_data_8cpp</filename>
    <includes id="_network_data_8h" name="NetworkData.h" local="yes" imported="no">NetworkData.h</includes>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_touchstone_8h" name="Touchstone.h" local="yes" imported="no">Touchstone.h</includes>
  </compound>
  <compound kind="file">
    <name>NetworkData.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/General/</path>
    <filename>_network_data_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <class kind="class">RsaToolbox::NetworkData</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>NetworkTraceData.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/General/</path>
    <filename>_network_trace_data_8cpp</filename>
    <includes id="_network_trace_data_8h" name="NetworkTraceData.h" local="yes" imported="no">NetworkTraceData.h</includes>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
  </compound>
  <compound kind="file">
    <name>NetworkTraceData.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/General/</path>
    <filename>_network_trace_data_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <includes id="_balanced_port_8h" name="BalancedPort.h" local="yes" imported="no">BalancedPort.h</includes>
    <class kind="class">RsaToolbox::NetworkTraceData</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>SnpStreamReader.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/General/</path>
    <filename>_snp_stream_reader_8cpp</filename>
    <includes id="_snp_stream_reader_8h" name="SnpStreamReader.h" local="yes" imported="no">SnpStreamReader.h</includes>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
  </compound>
  <compound kind="file">
    <name>SnpStreamReader.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/General/</path>
    <filename>_snp_stream_reader_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <class kind="class">RsaToolbox::SnpStreamReader</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>SnpStreamWriter.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/General/</path>
    <filename>_snp_stream_writer_8cpp</filename>
    <includes id="_snp_stream_writer_8h" name="SnpStreamWriter.h" local="yes" imported="no">SnpStreamWriter.h</includes>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
  </compound>
  <compound kind="file">
    <name>SnpStreamWriter.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/General/</path>
    <filename>_snp_stream_writer_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <class kind="class">RsaToolbox::SnpStreamWriter</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>Touchstone.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/General/</path>
    <filename>_touchstone_8cpp</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_touchstone_8h" name="Touchstone.h" local="yes" imported="no">Touchstone.h</includes>
  </compound>
  <compound kind="file">
    <name>Touchstone.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/General/</path>
    <filename>_touchstone_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <includes id="_network_data_8h" name="NetworkData.h" local="yes" imported="no">NetworkData.h</includes>
    <class kind="class">RsaToolbox::Touchstone</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>GenericInstrument.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/</path>
    <filename>_generic_instrument_8cpp</filename>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_generic_instrument_8h" name="GenericInstrument.h" local="yes" imported="no">GenericInstrument.h</includes>
    <includes id="_visa_bus_8h" name="VisaBus.h" local="yes" imported="no">VisaBus.h</includes>
    <includes id="_rsib_bus_8h" name="RsibBus.h" local="yes" imported="no">RsibBus.h</includes>
  </compound>
  <compound kind="file">
    <name>GenericInstrument.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/</path>
    <filename>_generic_instrument_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <includes id="_generic_bus_8h" name="GenericBus.h" local="yes" imported="no">GenericBus.h</includes>
    <includes id="_log_8h" name="Log.h" local="yes" imported="no">Log.h</includes>
    <class kind="class">RsaToolbox::GenericInstrument</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>Rsc.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Rsc/</path>
    <filename>_rsc_8cpp</filename>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_rsc_8h" name="Rsc.h" local="yes" imported="no">Rsc.h</includes>
    <includes id="_rsib_bus_8h" name="RsibBus.h" local="yes" imported="no">RsibBus.h</includes>
    <includes id="_visa_bus_8h" name="VisaBus.h" local="yes" imported="no">VisaBus.h</includes>
  </compound>
  <compound kind="file">
    <name>Rsc.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Rsc/</path>
    <filename>_rsc_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <includes id="_generic_bus_8h" name="GenericBus.h" local="yes" imported="no">GenericBus.h</includes>
    <includes id="_log_8h" name="Log.h" local="yes" imported="no">Log.h</includes>
    <class kind="class">RsaToolbox::Rsc</class>
    <namespace>RsaToolbox</namespace>
    <member kind="enumeration">
      <type></type>
      <name>RscCalibrationState</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>af41cc467667b3529f0b37438ed69b083</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>AF_RSC_CAL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>af41cc467667b3529f0b37438ed69b083af18952b7bf991ff22d53a70cc8e9268e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>FULL_RSC_CAL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>af41cc467667b3529f0b37438ed69b083aec9b8adfde0d2a94f3190a1c91c938eb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>OFF_RSC_CAL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>af41cc467667b3529f0b37438ed69b083ae5c4cfb9e9057bd9b3ecf4b9019b5ab3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>OFS_RSC_CAL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>af41cc467667b3529f0b37438ed69b083af1bf8db61bccc119314b47953b5388b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>RscModel</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4588f1880198c2106f18c903b6cb867b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RSC_02_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4588f1880198c2106f18c903b6cb867ba771d457554410c47eab728f2388217a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RSC_03_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4588f1880198c2106f18c903b6cb867bab6f053e7d24881f5a341eab2501b39e8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RSC_04_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4588f1880198c2106f18c903b6cb867ba0779cc9bc53e49651cbbf3a21e8d0876</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RSC_05_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4588f1880198c2106f18c903b6cb867ba4f6fe4aa89f08f5cf920d131cb542f9e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RSC_13_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4588f1880198c2106f18c903b6cb867ba6539fb0eb56784c1ad59e3882c924592</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RSC_14_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4588f1880198c2106f18c903b6cb867ba3a6df23307335cd02666a9d7941e168f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RSC_15_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4588f1880198c2106f18c903b6cb867ba15dca0b9be137e75c40cc1297328216f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RSC_Z405_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4588f1880198c2106f18c903b6cb867ba59263d2fc57cba1d6ddd281bd2369137</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RSC_Z675_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4588f1880198c2106f18c903b6cb867baf2f9222a8fdfc1754aeb8ea75dd5ee8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RSC_UNKNOWN_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4588f1880198c2106f18c903b6cb867bafe0bc45ee49148b564887d252c0b8cbe</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>RscCalState_To_String</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a6c8f7600af906cd94e77e80c918bab6a</anchor>
      <arglist>(RscCalibrationState state)</arglist>
    </member>
    <member kind="function">
      <type>RscCalibrationState</type>
      <name>Scpi_To_RscCalState</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad0161f77d312369c7399d89125ca8266</anchor>
      <arglist>(QString scpi)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>ToString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a3b7200506b30a6eb122bde8bc1449ce0</anchor>
      <arglist>(RscModel model)</arglist>
    </member>
    <member kind="function">
      <type>RscModel</type>
      <name>Scpi_to_RscModel</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a839354e4408d5916cde73829940fce8a</anchor>
      <arglist>(QString scpi)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Vna.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_8cpp</filename>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
    <includes id="_rsib_bus_8h" name="RsibBus.h" local="yes" imported="no">RsibBus.h</includes>
    <includes id="_visa_bus_8h" name="VisaBus.h" local="yes" imported="no">VisaBus.h</includes>
    <includes id="_index_name_8h" name="IndexName.h" local="yes" imported="no">IndexName.h</includes>
  </compound>
  <compound kind="file">
    <name>Vna.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <includes id="_generic_instrument_8h" name="GenericInstrument.h" local="yes" imported="no">GenericInstrument.h</includes>
    <includes id="_connector_8h" name="Connector.h" local="yes" imported="no">Connector.h</includes>
    <includes id="_name_label_8h" name="NameLabel.h" local="yes" imported="no">NameLabel.h</includes>
    <includes id="_vna_properties_8h" name="VnaProperties.h" local="yes" imported="no">VnaProperties.h</includes>
    <includes id="_vna_settings_8h" name="VnaSettings.h" local="yes" imported="no">VnaSettings.h</includes>
    <includes id="_vna_file_system_8h" name="VnaFileSystem.h" local="yes" imported="no">VnaFileSystem.h</includes>
    <includes id="_vna_cal_kit_8h" name="VnaCalKit.h" local="yes" imported="no">VnaCalKit.h</includes>
    <includes id="_vna_channel_8h" name="VnaChannel.h" local="yes" imported="no">VnaChannel.h</includes>
    <includes id="_vna_calibrate_8h" name="VnaCalibrate.h" local="yes" imported="no">VnaCalibrate.h</includes>
    <includes id="_vna_trace_8h" name="VnaTrace.h" local="yes" imported="no">VnaTrace.h</includes>
    <includes id="_vna_diagram_8h" name="VnaDiagram.h" local="yes" imported="no">VnaDiagram.h</includes>
    <includes id="_vna_switch_matrix_8h" name="VnaSwitchMatrix.h" local="yes" imported="no">VnaSwitchMatrix.h</includes>
    <includes id="_vna_cal_unit_8h" name="VnaCalUnit.h" local="yes" imported="no">VnaCalUnit.h</includes>
    <class kind="class">RsaToolbox::Vna</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>VnaAveraging.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_averaging_8cpp</filename>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_vna_averaging_8h" name="VnaAveraging.h" local="yes" imported="no">VnaAveraging.h</includes>
    <includes id="_vna_channel_8h" name="VnaChannel.h" local="yes" imported="no">VnaChannel.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaAveraging.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_averaging_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <class kind="class">RsaToolbox::VnaAveraging</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>VnaCalibrate.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_calibrate_8cpp</filename>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_vna_calibrate_8h" name="VnaCalibrate.h" local="yes" imported="no">VnaCalibrate.h</includes>
    <includes id="_vna_channel_8h" name="VnaChannel.h" local="yes" imported="no">VnaChannel.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaCalibrate.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_calibrate_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <includes id="_name_label_8h" name="NameLabel.h" local="yes" imported="no">NameLabel.h</includes>
    <includes id="_connector_8h" name="Connector.h" local="yes" imported="no">Connector.h</includes>
    <class kind="class">RsaToolbox::VnaCalibrate</class>
    <namespace>RsaToolbox</namespace>
    <member kind="enumeration">
      <type></type>
      <name>VnaCalType</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aed14be025d3f2c7af72c62ee0e516cb3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>OSM_CAL_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aed14be025d3f2c7af72c62ee0e516cb3a554dfea4df7807e32e2bccab7f2f4ed9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>TOSM_CAL_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aed14be025d3f2c7af72c62ee0e516cb3a6345cb79364488133bf14a315d43d066</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>UOSM_CAL_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aed14be025d3f2c7af72c62ee0e516cb3adabb6aa8b6c33457e170fe67804562a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toScpi</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a6cfc38382274ab6bba34041614b352eb</anchor>
      <arglist>(VnaCalType type)</arglist>
    </member>
    <member kind="function">
      <type>VnaCalType</type>
      <name>toVnaCalType</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a782487130b4a3c995371050f18ef6922</anchor>
      <arglist>(QString scpi)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>VnaCalKit.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_cal_kit_8cpp</filename>
    <includes id="_vna_cal_kit_8h" name="VnaCalKit.h" local="yes" imported="no">VnaCalKit.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaCalKit.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_cal_kit_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <includes id="_name_label_8h" name="NameLabel.h" local="yes" imported="no">NameLabel.h</includes>
    <includes id="_connector_8h" name="Connector.h" local="yes" imported="no">Connector.h</includes>
    <includes id="_vna_cal_standard_8h" name="VnaCalStandard.h" local="yes" imported="no">VnaCalStandard.h</includes>
    <class kind="class">RsaToolbox::VnaCalKit</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>VnaCalStandard.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_cal_standard_8cpp</filename>
    <includes id="_vna_cal_standard_8h" name="VnaCalStandard.h" local="yes" imported="no">VnaCalStandard.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaCalStandard.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_cal_standard_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <includes id="_connector_8h" name="Connector.h" local="yes" imported="no">Connector.h</includes>
    <includes id="_vna_standard_model_8h" name="VnaStandardModel.h" local="yes" imported="no">VnaStandardModel.h</includes>
    <class kind="class">RsaToolbox::VnaCalStandard</class>
    <namespace>RsaToolbox</namespace>
    <member kind="enumeration">
      <type></type>
      <name>VnaStandardType</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>OPEN_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aad716b85e0fcce01ecaf5c55a4a231203</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>SHORT_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aa4b7003004c7e0cf81631bc508559c26c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>OFFSET_SHORT_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aa62a71c7de147c37857281397efa8b58b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>OFFSET_SHORT2_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aae0c01dd6eee34f1cb7a6b997194e4e04</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>OFFSET_SHORT3_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aab7dc1b42121f8ed9838140913fcfe648</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>MATCH_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aa7bc1a902cca4bcec506dffb1cb1b164c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>SLIDING_MATCH_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aa7af320277cdd677322c64b1e5e63665d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>REFLECT_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aaf420b8b1a8320d2ce4b9168d93d1b6b7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>THRU_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aaf133c2cfb6637b93f572499a25cb82f7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>LINE_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aa3519843846cbff68f1074c676668c0cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>LINE2_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aacd137ddbb43287a71624dca6024fd3a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>LINE3_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aa7f2b1a3fc142f96da46d0a24ef8ab817</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ATTENUATION_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aaa9241aa03e902432d4a7d210120a72ee</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>SYMMETRIC_NETWORK_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aaee85c74e67a617084ae74c4bd185eb64</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>UNKNOWN_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aaba2dfb4dbc1f82f097268452c8b2e03d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>VnaCalUnit.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_cal_unit_8cpp</filename>
    <includes id="_vna_cal_unit_8h" name="VnaCalUnit.h" local="yes" imported="no">VnaCalUnit.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaCalUnit.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_cal_unit_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <class kind="class">RsaToolbox::VnaCalUnit</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>VnaChannel.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_channel_8cpp</filename>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_index_name_8h" name="IndexName.h" local="yes" imported="no">IndexName.h</includes>
    <includes id="_vna_channel_8h" name="VnaChannel.h" local="yes" imported="no">VnaChannel.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaChannel.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_channel_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <includes id="_balanced_port_8h" name="BalancedPort.h" local="yes" imported="no">BalancedPort.h</includes>
    <includes id="_vna_user_defined_port_8h" name="VnaUserDefinedPort.h" local="yes" imported="no">VnaUserDefinedPort.h</includes>
    <includes id="_vna_linear_sweep_8h" name="VnaLinearSweep.h" local="yes" imported="no">VnaLinearSweep.h</includes>
    <includes id="_vna_log_sweep_8h" name="VnaLogSweep.h" local="yes" imported="no">VnaLogSweep.h</includes>
    <includes id="_vna_segmented_sweep_8h" name="VnaSegmentedSweep.h" local="yes" imported="no">VnaSegmentedSweep.h</includes>
    <includes id="_vna_power_sweep_8h" name="VnaPowerSweep.h" local="yes" imported="no">VnaPowerSweep.h</includes>
    <includes id="_vna_cw_sweep_8h" name="VnaCwSweep.h" local="yes" imported="no">VnaCwSweep.h</includes>
    <includes id="_vna_time_sweep_8h" name="VnaTimeSweep.h" local="yes" imported="no">VnaTimeSweep.h</includes>
    <includes id="_vna_averaging_8h" name="VnaAveraging.h" local="yes" imported="no">VnaAveraging.h</includes>
    <includes id="_vna_corrections_8h" name="VnaCorrections.h" local="yes" imported="no">VnaCorrections.h</includes>
    <includes id="_vna_calibrate_8h" name="VnaCalibrate.h" local="yes" imported="no">VnaCalibrate.h</includes>
    <class kind="class">RsaToolbox::VnaChannel</class>
    <namespace>RsaToolbox</namespace>
    <member kind="enumeration">
      <type></type>
      <name>VnaSweepType</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a741a7a035d77e272e364af0697633c79</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>LINEAR_SWEEP</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a741a7a035d77e272e364af0697633c79ad061837f35d10d8b5eedb02b431a371d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>LOG_SWEEP</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a741a7a035d77e272e364af0697633c79a10cce66a1b3df251d7fbb11fd3b89d4c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>SEGMENTED_SWEEP</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a741a7a035d77e272e364af0697633c79a33f403a42a3aea0a67b63aec71da4836</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>POWER_SWEEP</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a741a7a035d77e272e364af0697633c79ad65f8c78351e3522fde3b5b8cb3d64a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>CW_SWEEP</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a741a7a035d77e272e364af0697633c79a72213c41d7382ad523167396ac788a40</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>TIME_SWEEP</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a741a7a035d77e272e364af0697633c79a62d23a952416a66f3d5a072bc9ced1f2</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toScpi</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ab2f2ea0a80a723ce1fdf99d005cb6c98</anchor>
      <arglist>(VnaSweepType sweepType)</arglist>
    </member>
    <member kind="function">
      <type>VnaSweepType</type>
      <name>toVnaSweepType</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a8341063968d06412b1c0713907e13df1</anchor>
      <arglist>(QString scpi)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>VnaCorrections.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_corrections_8cpp</filename>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_vna_corrections_8h" name="VnaCorrections.h" local="yes" imported="no">VnaCorrections.h</includes>
    <includes id="_vna_channel_8h" name="VnaChannel.h" local="yes" imported="no">VnaChannel.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaCorrections.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_corrections_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <class kind="class">RsaToolbox::VnaCorrections</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>VnaCwSweep.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_cw_sweep_8cpp</filename>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_vna_cw_sweep_8h" name="VnaCwSweep.h" local="yes" imported="no">VnaCwSweep.h</includes>
    <includes id="_vna_channel_8h" name="VnaChannel.h" local="yes" imported="no">VnaChannel.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaCwSweep.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_cw_sweep_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <class kind="class">RsaToolbox::VnaCwSweep</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>VnaDiagram.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_diagram_8cpp</filename>
    <includes id="_vna_diagram_8h" name="VnaDiagram.h" local="yes" imported="no">VnaDiagram.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaDiagram.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_diagram_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <class kind="class">RsaToolbox::VnaDiagram</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>VnaFileSystem.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_file_system_8cpp</filename>
    <includes id="_vna_file_system_8h" name="VnaFileSystem.h" local="yes" imported="no">VnaFileSystem.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaFileSystem.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_file_system_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <class kind="class">RsaToolbox::VnaFileSystem</class>
    <namespace>RsaToolbox</namespace>
    <member kind="enumeration">
      <type></type>
      <name>VnaDirectory</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4af5109825e24daf9ac1de596dc44850</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DEFAULT_DIRECTORY</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4af5109825e24daf9ac1de596dc44850aba70ab56c8497a5155e06e7bc42b3ec7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>EMBED_DIRECTORY</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4af5109825e24daf9ac1de596dc44850ac3bdae926d1a34444e8fa1441525fe32</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DEEMBED_DIRECTORY</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4af5109825e24daf9ac1de596dc44850ade6246814a395c7ccef887fc7c30a9c2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>CAL_GROUP_DIRECTORY</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4af5109825e24daf9ac1de596dc44850aeeb197361de055a6fe6523e31cc3f081</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>CAL_KIT_DIRECTORY</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4af5109825e24daf9ac1de596dc44850a981832126da42584e99723f632952208</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>EXTERNAL_TOOLS_DIRECTORY</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4af5109825e24daf9ac1de596dc44850a1fb38160435656bb12debb661fe4b555</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RECALL_SETS_DIRECTORY</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4af5109825e24daf9ac1de596dc44850a6d5ca8263124d28188c8bdf85edc0d65</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>TRACES_DIRECTORY</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4af5109825e24daf9ac1de596dc44850a9f9f8a45c0bcdf2c9ec7aad9c02ab60d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>VnaLinearSweep.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_linear_sweep_8cpp</filename>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_vna_linear_sweep_8h" name="VnaLinearSweep.h" local="yes" imported="no">VnaLinearSweep.h</includes>
    <includes id="_vna_channel_8h" name="VnaChannel.h" local="yes" imported="no">VnaChannel.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaLinearSweep.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_linear_sweep_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <includes id="_network_data_8h" name="NetworkData.h" local="yes" imported="no">NetworkData.h</includes>
    <class kind="class">RsaToolbox::VnaLinearSweep</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>VnaLogSweep.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_log_sweep_8cpp</filename>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_vna_log_sweep_8h" name="VnaLogSweep.h" local="yes" imported="no">VnaLogSweep.h</includes>
    <includes id="_vna_channel_8h" name="VnaChannel.h" local="yes" imported="no">VnaChannel.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaLogSweep.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_log_sweep_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <includes id="_network_data_8h" name="NetworkData.h" local="yes" imported="no">NetworkData.h</includes>
    <class kind="class">RsaToolbox::VnaLogSweep</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>VnaMarker.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_marker_8cpp</filename>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_vna_marker_8h" name="VnaMarker.h" local="yes" imported="no">VnaMarker.h</includes>
    <includes id="_vna_channel_8h" name="VnaChannel.h" local="yes" imported="no">VnaChannel.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaMarker.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_marker_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <class kind="class">RsaToolbox::VnaMarker</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>VnaPowerCalibrate.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_power_calibrate_8cpp</filename>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_vna_power_calibrate_8h" name="VnaPowerCalibrate.h" local="yes" imported="no">VnaPowerCalibrate.h</includes>
    <includes id="_vna_channel_8h" name="VnaChannel.h" local="yes" imported="no">VnaChannel.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaPowerCalibrate.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_power_calibrate_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <includes id="_name_label_8h" name="NameLabel.h" local="yes" imported="no">NameLabel.h</includes>
    <includes id="_connector_8h" name="Connector.h" local="yes" imported="no">Connector.h</includes>
    <class kind="class">RsaToolbox::VnaPowerCalibrate</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>VnaPowerCorrections.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_power_corrections_8cpp</filename>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_vna_power_corrections_8h" name="VnaPowerCorrections.h" local="yes" imported="no">VnaPowerCorrections.h</includes>
    <includes id="_vna_channel_8h" name="VnaChannel.h" local="yes" imported="no">VnaChannel.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaPowerCorrections.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_power_corrections_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <class kind="class">RsaToolbox::VnaPowerCorrections</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>VnaPowerSweep.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_power_sweep_8cpp</filename>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_vna_power_sweep_8h" name="VnaPowerSweep.h" local="yes" imported="no">VnaPowerSweep.h</includes>
    <includes id="_vna_channel_8h" name="VnaChannel.h" local="yes" imported="no">VnaChannel.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaPowerSweep.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_power_sweep_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <class kind="class">RsaToolbox::VnaPowerSweep</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>VnaProperties.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_properties_8cpp</filename>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
    <includes id="_vna_properties_8h" name="VnaProperties.h" local="yes" imported="no">VnaProperties.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaProperties.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_properties_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <class kind="class">RsaToolbox::VnaProperties</class>
    <namespace>RsaToolbox</namespace>
    <member kind="enumeration">
      <type></type>
      <name>VnaModel</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad855d80aa0cfd97d333966940fa8ea01</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ZVA_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad855d80aa0cfd97d333966940fa8ea01a2d51e423a09a3c2b3153aa2cea9a598c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ZVB_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad855d80aa0cfd97d333966940fa8ea01a5da95a0c91001bfb794b9b94965535ac</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ZVH_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad855d80aa0cfd97d333966940fa8ea01adba63c59378b92096fab4185be6b9d8d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ZVL_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad855d80aa0cfd97d333966940fa8ea01a1f5f1ba03530b290a088a2f902558de2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ZVT_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad855d80aa0cfd97d333966940fa8ea01a65d730cf6fef22b7c351a5eaf3f1390d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ZNB_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad855d80aa0cfd97d333966940fa8ea01ad2368b2cd5f0cc866f4bce111466684e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ZNBT_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad855d80aa0cfd97d333966940fa8ea01af13fef3f36941ed7498d28362babbb81</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ZNC_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad855d80aa0cfd97d333966940fa8ea01a7066fd4bb8edb717a681bdfa6c8f6960</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ZNP_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad855d80aa0cfd97d333966940fa8ea01a84ddb44271f00d058dbd9a6275361a06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>UNKNOWN_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad855d80aa0cfd97d333966940fa8ea01a3f3d79136caf882d83cc87d6b5f5478e</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a803ac7720b39828537ed067e2e5b1599</anchor>
      <arglist>(VnaModel model)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toSetFileExtension</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>abc530d8cc4fb4af9cbb2b389122b97cd</anchor>
      <arglist>(VnaModel model)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>VnaReferenceMarker.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_reference_marker_8cpp</filename>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_vna_reference_marker_8h" name="VnaReferenceMarker.h" local="yes" imported="no">VnaReferenceMarker.h</includes>
    <includes id="_vna_channel_8h" name="VnaChannel.h" local="yes" imported="no">VnaChannel.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaReferenceMarker.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_reference_marker_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <class kind="class">RsaToolbox::VnaReferenceMarker</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>VnaSegmentedSweep.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_segmented_sweep_8cpp</filename>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_vna_segmented_sweep_8h" name="VnaSegmentedSweep.h" local="yes" imported="no">VnaSegmentedSweep.h</includes>
    <includes id="_vna_channel_8h" name="VnaChannel.h" local="yes" imported="no">VnaChannel.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaSegmentedSweep.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_segmented_sweep_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <includes id="_network_data_8h" name="NetworkData.h" local="yes" imported="no">NetworkData.h</includes>
    <includes id="_vna_sweep_segment_8h" name="VnaSweepSegment.h" local="yes" imported="no">VnaSweepSegment.h</includes>
    <class kind="class">RsaToolbox::VnaSegmentedSweep</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>VnaSettings.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_settings_8cpp</filename>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_vna_settings_8h" name="VnaSettings.h" local="yes" imported="no">VnaSettings.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaSettings.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_settings_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <class kind="class">RsaToolbox::VnaSettings</class>
    <namespace>RsaToolbox</namespace>
    <member kind="enumeration">
      <type></type>
      <name>VnaEmulationMode</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7d4a7e8a70dfbbc32a553dabe2381f4a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>NO_EMULATION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7d4a7e8a70dfbbc32a553dabe2381f4aa1c62780b1b015465ebad1ca53372d23c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>PNA_EMULATION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7d4a7e8a70dfbbc32a553dabe2381f4aa157713b030dfccebbc8a2333fe49c9ca</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>HP_8510_EMULATION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7d4a7e8a70dfbbc32a553dabe2381f4aa738dcbf912d1eab23b3ae0f7ba2e6261</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>HP_8720_EMULATION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7d4a7e8a70dfbbc32a553dabe2381f4aa73c91c970186c6170831e63b1dc29144</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>HP_8753_EMULATION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7d4a7e8a70dfbbc32a553dabe2381f4aab8a7323b95539d70c78068f248e10c6c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>HP_8714_EMULATION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7d4a7e8a70dfbbc32a553dabe2381f4aa1c284ab1efe315e9ff36c97c29e18990</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ZVR_EMULATION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7d4a7e8a70dfbbc32a553dabe2381f4aa9a1fd28ed6cbe66c21b62d5cb5c7b7c5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>HP_8530_EMULATION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7d4a7e8a70dfbbc32a553dabe2381f4aa2f6231df7774966492dc80879e4e4f3f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ENA_EMULATION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7d4a7e8a70dfbbc32a553dabe2381f4aaaf6487e48db7292fc40262e932807261</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ZVABT_EMULATION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7d4a7e8a70dfbbc32a553dabe2381f4aac08429b0441ae1aca82fff832f5e0552</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>VnaColorScheme</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ae54ff682cf8310c58191f1b6349e09f5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DARK_BACKGROUND</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ae54ff682cf8310c58191f1b6349e09f5ac0208f506c01bf8d6a77ed681d44a376</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>LIGHT_BACKGROUND</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ae54ff682cf8310c58191f1b6349e09f5a99b64d93fc67c275192cf880466350fb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>BLACK_WHITE_OUTLINE_BACKGROUND</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ae54ff682cf8310c58191f1b6349e09f5a407aefbf802d2adb32a015d0e88b630b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>BLACK_WHITE_SOLID_BACKGROUND</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ae54ff682cf8310c58191f1b6349e09f5a1fe79d0781fe8bd380e1a5cd78c3eb46</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>VnaStandardModel.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_standard_model_8cpp</filename>
    <includes id="_vna_standard_model_8h" name="VnaStandardModel.h" local="yes" imported="no">VnaStandardModel.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaStandardModel.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_standard_model_8h</filename>
    <class kind="class">RsaToolbox::VnaStandardModel</class>
    <namespace>RsaToolbox</namespace>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a98f28e7bd9f52e4fda5411eacfd8a98a</anchor>
      <arglist>(VnaStandardModel const &amp;left, VnaStandardModel const &amp;right)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4bb4255a1505d989988bf4e5bf6968cf</anchor>
      <arglist>(VnaStandardModel const &amp;left, VnaStandardModel const &amp;right)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>VnaSweepSegment.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_sweep_segment_8cpp</filename>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_vna_sweep_segment_8h" name="VnaSweepSegment.h" local="yes" imported="no">VnaSweepSegment.h</includes>
    <includes id="_vna_channel_8h" name="VnaChannel.h" local="yes" imported="no">VnaChannel.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaSweepSegment.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_sweep_segment_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <class kind="class">RsaToolbox::VnaSweepSegment</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>VnaSwitchMatrix.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_switch_matrix_8cpp</filename>
    <includes id="_vna_switch_matrix_8h" name="VnaSwitchMatrix.h" local="yes" imported="no">VnaSwitchMatrix.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaSwitchMatrix.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_switch_matrix_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <class kind="class">RsaToolbox::VnaSwitchMatrix</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>VnaTimeDomain.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_time_domain_8cpp</filename>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_vna_time_domain_8h" name="VnaTimeDomain.h" local="yes" imported="no">VnaTimeDomain.h</includes>
    <includes id="_vna_channel_8h" name="VnaChannel.h" local="yes" imported="no">VnaChannel.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaTimeDomain.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_time_domain_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <class kind="class">RsaToolbox::VnaTimeDomain</class>
    <namespace>RsaToolbox</namespace>
    <member kind="enumeration">
      <type></type>
      <name>VnaWindowFunction</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ade955acccb31f71d24b4e5458b7b742e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>REGULAR_WINDOW_FUNCTION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ade955acccb31f71d24b4e5458b7b742ea3b58f436f7b0999dbe0f8aa96dc0330e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>HAMMING_WINDOW_FUNCTION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ade955acccb31f71d24b4e5458b7b742ea007b1aba6911a0756f2947be7e9c364a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>HANN_WINDOW_FUNCTION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ade955acccb31f71d24b4e5458b7b742ea33b4bddabfe425dad335558453cb69f7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>BOHMAN_WINDOW_FUNCTION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ade955acccb31f71d24b4e5458b7b742ea685fd608f32061c752bf01044ace1d66</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DOLPH_CHEBYCHEV_WINDOW_FUNCTION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ade955acccb31f71d24b4e5458b7b742ea747deaadb3f99845690e7e8b8ce0e8c6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>RiseTimeDefinition</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1f109c762bc8b7db640633c8a9b4f5f7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RISETIME_20_TO_80</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1f109c762bc8b7db640633c8a9b4f5f7a5499071d72009edb7df61b9a656215f8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RISETIME_10_TO_90</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1f109c762bc8b7db640633c8a9b4f5f7a81117b8a1f5d9bafbbf95c6bf937dd22</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>VnaTimeSweep.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_time_sweep_8cpp</filename>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_vna_time_sweep_8h" name="VnaTimeSweep.h" local="yes" imported="no">VnaTimeSweep.h</includes>
    <includes id="_vna_channel_8h" name="VnaChannel.h" local="yes" imported="no">VnaChannel.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaTimeSweep.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_time_sweep_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <class kind="class">RsaToolbox::VnaTimeSweep</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>VnaTrace.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_trace_8cpp</filename>
    <includes id="_vna_trace_8h" name="VnaTrace.h" local="yes" imported="no">VnaTrace.h</includes>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaTrace.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_trace_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <includes id="_balanced_port_8h" name="BalancedPort.h" local="yes" imported="no">BalancedPort.h</includes>
    <includes id="_network_trace_data_8h" name="NetworkTraceData.h" local="yes" imported="no">NetworkTraceData.h</includes>
    <includes id="_vna_marker_8h" name="VnaMarker.h" local="yes" imported="no">VnaMarker.h</includes>
    <includes id="_vna_reference_marker_8h" name="VnaReferenceMarker.h" local="yes" imported="no">VnaReferenceMarker.h</includes>
    <includes id="_vna_time_domain_8h" name="VnaTimeDomain.h" local="yes" imported="no">VnaTimeDomain.h</includes>
    <class kind="class">RsaToolbox::VnaTrace</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>VnaUserDefinedPort.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_user_defined_port_8cpp</filename>
    <includes id="_vna_user_defined_port_8h" name="VnaUserDefinedPort.h" local="yes" imported="no">VnaUserDefinedPort.h</includes>
  </compound>
  <compound kind="file">
    <name>VnaUserDefinedPort.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>_vna_user_defined_port_8h</filename>
    <class kind="class">RsaToolbox::VnaUserDefinedPort</class>
    <namespace>RsaToolbox</namespace>
    <member kind="enumeration">
      <type></type>
      <name>VnaReceiver</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a0caf3cd1fce8615b0f926b3320173aa9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RECEIVER_A</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a0caf3cd1fce8615b0f926b3320173aa9a5141c5dc95df12f1f9fe8d37b6e345f8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RECEIVER_B</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a0caf3cd1fce8615b0f926b3320173aa9a9884a31097eeb934843ac3eeab240dce</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toScpi</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a5fbe812a0f21ba533aee3717affc28b7</anchor>
      <arglist>(VnaReceiver receiver)</arglist>
    </member>
    <member kind="function">
      <type>VnaReceiver</type>
      <name>toVnaReceiver</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a8d575d47dbb967f85fc36439d58aff23</anchor>
      <arglist>(QString scpi)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toScpi</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a5bc79df0bf071f46c615bc832eec4b72</anchor>
      <arglist>(VnaUserDefinedPort userDefinedPort)</arglist>
    </member>
    <member kind="function">
      <type>VnaUserDefinedPort</type>
      <name>toUserDefinedPort</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>abf29c95c84ba00760dbdb51885aaa2c0</anchor>
      <arglist>(QString scpi)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a88ba0257d35cfbf6aabd3f3d76399374</anchor>
      <arglist>(VnaUserDefinedPort const &amp;left, VnaUserDefinedPort const &amp;right)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afc8e915bbe9d7bdf5e912927d469ccc7</anchor>
      <arglist>(VnaUserDefinedPort const &amp;left, VnaUserDefinedPort const &amp;right)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Log.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Log/</path>
    <filename>_log_8cpp</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <includes id="_log_8h" name="Log.h" local="yes" imported="no">Log.h</includes>
  </compound>
  <compound kind="file">
    <name>Log.h</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Log/</path>
    <filename>_log_8h</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <class kind="class">RsaToolbox::Log</class>
    <namespace>RsaToolbox</namespace>
  </compound>
  <compound kind="file">
    <name>main.cpp</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/</path>
    <filename>main_8cpp</filename>
    <includes id="_definitions_8h" name="Definitions.h" local="yes" imported="no">Definitions.h</includes>
    <includes id="_general_8h" name="General.h" local="yes" imported="no">General.h</includes>
    <includes id="_visa_bus_8h" name="VisaBus.h" local="yes" imported="no">VisaBus.h</includes>
    <includes id="_vna_8h" name="Vna.h" local="yes" imported="no">Vna.h</includes>
    <includes id="_network_data_8h" name="NetworkData.h" local="yes" imported="no">NetworkData.h</includes>
    <includes id="_snp_stream_reader_8h" name="SnpStreamReader.h" local="yes" imported="no">SnpStreamReader.h</includes>
    <includes id="_snp_stream_writer_8h" name="SnpStreamWriter.h" local="yes" imported="no">SnpStreamWriter.h</includes>
    <includes id="_log_8h" name="Log.h" local="yes" imported="no">Log.h</includes>
    <member kind="function">
      <type>int</type>
      <name>main</name>
      <anchorfile>main_8cpp.html</anchorfile>
      <anchor>a0ddf1224851353fc92bfbff6f499fa97</anchor>
      <arglist>(int argc, char *argv[])</arglist>
    </member>
  </compound>
  <compound kind="page">
    <name>Log</name>
    <title></title>
    <filename>_log</filename>
  </compound>
  <compound kind="page">
    <name>Bus</name>
    <title></title>
    <filename>_bus</filename>
  </compound>
  <compound kind="page">
    <name>Instrument</name>
    <title></title>
    <filename>_instrument</filename>
  </compound>
  <compound kind="page">
    <name>Templates</name>
    <title></title>
    <filename>_templates</filename>
  </compound>
  <compound kind="page">
    <name>Installer</name>
    <title></title>
    <filename>_installer</filename>
  </compound>
  <compound kind="group">
    <name>BusGroup</name>
    <title>Bus</title>
    <filename>group___bus_group.html</filename>
    <class kind="class">RsaToolbox::GenericBus</class>
    <class kind="class">RsaToolbox::RsibBus</class>
    <class kind="class">RsaToolbox::VisaBus</class>
  </compound>
  <compound kind="group">
    <name>InstrumentGroup</name>
    <title>Instrument</title>
    <filename>group___instrument_group.html</filename>
    <subgroup>GenericInstrumentGroup</subgroup>
    <subgroup>VnaGroup</subgroup>
  </compound>
  <compound kind="group">
    <name>GenericInstrumentGroup</name>
    <title>GenericInstrument</title>
    <filename>group___generic_instrument_group.html</filename>
    <class kind="class">RsaToolbox::GenericInstrument</class>
  </compound>
  <compound kind="group">
    <name>VnaGroup</name>
    <title>Vna</title>
    <filename>group___vna_group.html</filename>
    <class kind="class">RsaToolbox::Vna</class>
    <class kind="class">RsaToolbox::VnaCalibrate</class>
    <class kind="class">RsaToolbox::VnaCalKit</class>
    <class kind="class">RsaToolbox::VnaCalStandard</class>
    <class kind="class">RsaToolbox::VnaCalUnit</class>
    <class kind="class">RsaToolbox::VnaChannel</class>
    <class kind="class">RsaToolbox::VnaCorrections</class>
    <class kind="class">RsaToolbox::VnaCwSweep</class>
    <class kind="class">RsaToolbox::VnaDiagram</class>
    <class kind="class">RsaToolbox::VnaFileSystem</class>
    <class kind="class">RsaToolbox::VnaLinearSweep</class>
    <class kind="class">RsaToolbox::VnaLogSweep</class>
    <class kind="class">RsaToolbox::VnaMarker</class>
    <class kind="class">RsaToolbox::VnaPowerCalibrate</class>
    <class kind="class">RsaToolbox::VnaPowerCorrections</class>
    <class kind="class">RsaToolbox::VnaPowerSweep</class>
    <class kind="class">RsaToolbox::VnaProperties</class>
    <class kind="class">RsaToolbox::VnaReferenceMarker</class>
    <class kind="class">RsaToolbox::VnaSegmentedSweep</class>
    <class kind="class">RsaToolbox::VnaSettings</class>
    <class kind="class">RsaToolbox::VnaStandardModel</class>
    <class kind="class">RsaToolbox::VnaSweepSegment</class>
    <class kind="class">RsaToolbox::VnaSwitchMatrix</class>
    <class kind="class">RsaToolbox::VnaTimeDomain</class>
    <class kind="class">RsaToolbox::VnaTimeSweep</class>
    <class kind="class">RsaToolbox::VnaTrace</class>
    <class kind="class">RsaToolbox::VnaUserDefinedPort</class>
  </compound>
  <compound kind="group">
    <name>LogGroup</name>
    <title>Log</title>
    <filename>group___log_group.html</filename>
    <class kind="class">RsaToolbox::Log</class>
  </compound>
  <compound kind="namespace">
    <name>RsaToolbox</name>
    <filename>namespace_rsa_toolbox.html</filename>
    <class kind="class">RsaToolbox::BalancedPort</class>
    <class kind="class">RsaToolbox::Connector</class>
    <class kind="class">RsaToolbox::GenericBus</class>
    <class kind="class">RsaToolbox::GenericInstrument</class>
    <class kind="class">RsaToolbox::IndexName</class>
    <class kind="class">RsaToolbox::Key</class>
    <class kind="class">RsaToolbox::Log</class>
    <class kind="class">RsaToolbox::NameLabel</class>
    <class kind="class">RsaToolbox::NetworkData</class>
    <class kind="class">RsaToolbox::NetworkTraceData</class>
    <class kind="class">RsaToolbox::Rsc</class>
    <class kind="class">RsaToolbox::RsibBus</class>
    <class kind="class">RsaToolbox::SnpStreamReader</class>
    <class kind="class">RsaToolbox::SnpStreamWriter</class>
    <class kind="class">RsaToolbox::Touchstone</class>
    <class kind="class">RsaToolbox::VisaBus</class>
    <class kind="class">RsaToolbox::Vna</class>
    <class kind="class">RsaToolbox::VnaAveraging</class>
    <class kind="class">RsaToolbox::VnaCalibrate</class>
    <class kind="class">RsaToolbox::VnaCalKit</class>
    <class kind="class">RsaToolbox::VnaCalStandard</class>
    <class kind="class">RsaToolbox::VnaCalUnit</class>
    <class kind="class">RsaToolbox::VnaChannel</class>
    <class kind="class">RsaToolbox::VnaCorrections</class>
    <class kind="class">RsaToolbox::VnaCwSweep</class>
    <class kind="class">RsaToolbox::VnaDiagram</class>
    <class kind="class">RsaToolbox::VnaFileSystem</class>
    <class kind="class">RsaToolbox::VnaLinearSweep</class>
    <class kind="class">RsaToolbox::VnaLogSweep</class>
    <class kind="class">RsaToolbox::VnaMarker</class>
    <class kind="class">RsaToolbox::VnaPowerCalibrate</class>
    <class kind="class">RsaToolbox::VnaPowerCorrections</class>
    <class kind="class">RsaToolbox::VnaPowerSweep</class>
    <class kind="class">RsaToolbox::VnaProperties</class>
    <class kind="class">RsaToolbox::VnaReferenceMarker</class>
    <class kind="class">RsaToolbox::VnaSegmentedSweep</class>
    <class kind="class">RsaToolbox::VnaSettings</class>
    <class kind="class">RsaToolbox::VnaStandardModel</class>
    <class kind="class">RsaToolbox::VnaSweepSegment</class>
    <class kind="class">RsaToolbox::VnaSwitchMatrix</class>
    <class kind="class">RsaToolbox::VnaTimeDomain</class>
    <class kind="class">RsaToolbox::VnaTimeSweep</class>
    <class kind="class">RsaToolbox::VnaTrace</class>
    <class kind="class">RsaToolbox::VnaUserDefinedPort</class>
    <member kind="typedef">
      <type>std::complex&lt; double &gt;</type>
      <name>ComplexDouble</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ab82a545355b9d90ede8e612bf1bcb9ed</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; ComplexDouble &gt;</type>
      <name>ComplexRowVector</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aeff8cbc6faa565bb58d8f7467e117ae0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; ComplexRowVector &gt;</type>
      <name>ComplexMatrix2D</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aaf2b301924485eee4bed8606937522b6</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; ComplexMatrix2D &gt;</type>
      <name>ComplexMatrix3D</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a38e11e9315a74fce00f201a19143d587</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; double &gt;</type>
      <name>RowVector</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a377a6286f7e32baef3ecb46643772d71</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; RowVector &gt;</type>
      <name>Matrix2D</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4ac77922c110de258891e9f867b98a53</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; Matrix2D &gt;</type>
      <name>Matrix3D</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ba044817ed0459f04f0bc9e98f771c0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>QVector&lt; double &gt;</type>
      <name>QRowVector</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a277781f27cd64e7b4d0728b64ace87b8</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>QVector&lt; QRowVector &gt;</type>
      <name>QMatrix2D</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a3579c091e3c712a5242d147bc08b1762</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>QVector&lt; QMatrix2D &gt;</type>
      <name>QMatrix3D</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac184c78328efc65ad0e0f17890004fb7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>ConnectionType</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa1f0e2efd52935fd01bfece0fbead81f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>TCPIP_CONNECTION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa1f0e2efd52935fd01bfece0fbead81fa14c1f2316495d5cd32f37c7423fce72c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>GPIB_CONNECTION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa1f0e2efd52935fd01bfece0fbead81fa0fa118c77d3b0455c890e59388c6e347</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>USB_CONNECTION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa1f0e2efd52935fd01bfece0fbead81fa5d196bbeccdb8265b1082c35c3ee7b9f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>NO_CONNECTION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa1f0e2efd52935fd01bfece0fbead81facad28945d500e3fc972e2d1c3b948e8e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>BalancedPortType</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>acf1ebdd21871818fe315b47399550e12</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>SINGLE_ENDED</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>acf1ebdd21871818fe315b47399550e12aa5cea233f1879638f5a8eb18d6d87bd2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DIFFERENTIAL_MODE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>acf1ebdd21871818fe315b47399550e12ad1ac4eb333998510c340c1f9a78cff3f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>COMMON_MODE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>acf1ebdd21871818fe315b47399550e12a61c06effc644df0555d6f1a8cff5c83a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>ConnectorType</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>N_50_OHM_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6a61b16617c1ce5333d8c027318e8529fd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>N_75_OHM_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6a18904b59a1ded80dad70fa26ab7433ce</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>mm_7_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6aadf3cc24bafb07a62442c480f517b1fd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>mm_3_5_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6a4e914111258e64e9d4e2f0dbe3a2861e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>mm_2_92_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6a7d63e1ba4ae171f55faa48f6fbd1ee4b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>mm_2_4_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6ae5d22d314468dd08f9106c11c7788c40</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>mm_1_85_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6aab51064780378a3d667507fe8c99c4eb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>in_7_16_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6a820b27227c0cde3279db47be215854f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>TYPE_F_75_OHM_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6aba8a6d93ba5c67bec16f42bdf0f89db1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>BNC_50_OHM_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6ad8eb9947a41587a9b042b29f41a5b6e1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>BNC_75_OHM_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6a92016eee17a35da7bc24a7c67fdd31bb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>CUSTOM_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6ac9743d7b99ee46ae162cae020a155a2a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>UNKNOWN_CONNECTOR</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a086c6f6507c67c8809b218d90998c5d6a6a1586a3f010b4d1fa0be495c37c400f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>ConnectorGender</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a157ffe0e4dcd14784420ca337c6251a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>MALE_GENDER</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a157ffe0e4dcd14784420ca337c6251a1a9cfa23a30f4229b999a85cb0d577336a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>FEMALE_GENDER</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a157ffe0e4dcd14784420ca337c6251a1abc9baaf3a3a3b0b5eb7bdc25e1cac3de</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>NEUTRAL_GENDER</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a157ffe0e4dcd14784420ca337c6251a1a7faa7e6fb3376fa753cc5904fe40250e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>NetworkParameter</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa0ba4d0acd5fdf65863b14e183a9f1d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>S_PARAMETER</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa0ba4d0acd5fdf65863b14e183a9f1d8a83bb3bbd6a83a05fdbedc08fb53899fb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>Y_PARAMETER</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa0ba4d0acd5fdf65863b14e183a9f1d8a55de577f0f89545831b061382c6f97cf</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>Z_PARAMETER</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa0ba4d0acd5fdf65863b14e183a9f1d8abe9267f948ce9e69f2fea2fcee4f3a6f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>H_PARAMETER</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa0ba4d0acd5fdf65863b14e183a9f1d8afa76d9d5eddc128ea577e1a56aaa61c1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>G_PARAMETER</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa0ba4d0acd5fdf65863b14e183a9f1d8af616d0899e2406c6b505f1eaf9c1982d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>WaveQuantity</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad510ffc5b80ffa73e4165154fb790ef0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>A_WAVE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad510ffc5b80ffa73e4165154fb790ef0a3782fc4390ea544b078c2e11f8223f2c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>B_WAVE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad510ffc5b80ffa73e4165154fb790ef0aa86233ccbb7f4656d9f615f2e4a83dc5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>ReferenceLevel</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac2904dcef8205419855c49db4819d430</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RELATIVE_REFERENCE_LEVEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac2904dcef8205419855c49db4819d430a8d64deccd5f19fcee8b738285d325212</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ABSOLUTE_REFERENCE_LEVEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac2904dcef8205419855c49db4819d430a5abb6dfad5d133615e921ed3ff84d3f7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>TraceFormat</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a410a23bf00f6ac6aa86b91b31688806e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DB_MAGNITUDE_TRACE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a410a23bf00f6ac6aa86b91b31688806ea9d68efc32366135baa8c1c5e1b165f70</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>PHASE_DEG_TRACE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a410a23bf00f6ac6aa86b91b31688806ea3ec0bed6d4db74c6fcf94c68a0515ad9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>SMITH_CHART_TRACE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a410a23bf00f6ac6aa86b91b31688806eaf5132fcff918f839752b73ee3b10f880</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>POLAR_CHART_TRACE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a410a23bf00f6ac6aa86b91b31688806ea01f908e0790e62d02a879eeb09dc2823</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>VSWR_TRACE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a410a23bf00f6ac6aa86b91b31688806eaab675c23e794f71b66b3426a7118ccb0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>UNWRAP_PHASE_DEG_TRACE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a410a23bf00f6ac6aa86b91b31688806ea7b48bf464a21b7e8c0a95e0dead6f416</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>LINEAR_MAGNITUDE_TRACE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a410a23bf00f6ac6aa86b91b31688806ea5c7dc179b59b3b6e9bbd746bca718998</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>INVERSE_SMITH_CHART_TRACE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a410a23bf00f6ac6aa86b91b31688806ea5f3f338f813dd9e2c70b01af96eb4e13</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>REAL_PART_TRACE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a410a23bf00f6ac6aa86b91b31688806eac3a012c86fd1233de20b73b7bc05cd4b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>IMAGINARY_PART_TRACE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a410a23bf00f6ac6aa86b91b31688806eaaac708e187a6f005eb3925a7c1b5cd5f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DELAY_TRACE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a410a23bf00f6ac6aa86b91b31688806ea6c6bf22bb32e5758f4244b7adda0b8b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>CsvFormat</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afef9eb6dfe949b834d1b5b9d7e09d3ff</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>COMPLEX_DB_DEGREES_CSV</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afef9eb6dfe949b834d1b5b9d7e09d3ffa70dafe8e6d387e15403095e22242e536</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>COMPLEX_DB_RADIANS_CSV</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afef9eb6dfe949b834d1b5b9d7e09d3ffabcbae8db0109867d90d1587e730350fd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>COMPLEX_MAGNITUDE_DEGREES_CSV</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afef9eb6dfe949b834d1b5b9d7e09d3ffa7296e99e61aaec591a6defc0ae92dc4b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>COMPLEX_MAGNITUDE_RADIANS_CSV</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afef9eb6dfe949b834d1b5b9d7e09d3ffa045d8c588b42f9a6d6a581df9a18d56c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>COMPLEX_REAL_IMAGINARY_CSV</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afef9eb6dfe949b834d1b5b9d7e09d3ffa45f23fcf5d539cb4c309e022447acd51</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DECIBEL_MAGNITUDE_CSV</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afef9eb6dfe949b834d1b5b9d7e09d3ffa444a10677d50dbc91523a3377c5d9a90</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>MAGNITUDE_CSV</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afef9eb6dfe949b834d1b5b9d7e09d3ffa727b130c38095cde28e2a3624f6cf228</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>PHASE_DEGREES_CSV</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afef9eb6dfe949b834d1b5b9d7e09d3ffa09e5e4f652e0c6406919320dc1b534b3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>PHASE_RADIANS_CSV</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afef9eb6dfe949b834d1b5b9d7e09d3ffa65f4b2c5ca299bc0dcd2d722aec1b819</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>VSWR_CSV</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afef9eb6dfe949b834d1b5b9d7e09d3ffa27217d9450c80405548664c337e26ee4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>ComplexFormat</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a3fd1a9b25d76e60c5b6c4d86356986e9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DB_DEGREES_COMPLEX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a3fd1a9b25d76e60c5b6c4d86356986e9a925c3bdac31e15282640b1c5290ee62c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>MAGNITUDE_DEGREES_COMPLEX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a3fd1a9b25d76e60c5b6c4d86356986e9ac191a8ef9712fcb2ee164739bed9c025</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>REAL_IMAGINARY_COMPLEX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a3fd1a9b25d76e60c5b6c4d86356986e9a9c6c267b96c0f262fb37ed5ef2b21c7d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>Units</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac33d2b1fdba15c8bfb494f9cf0ef4190</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>NO_UNITS</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac33d2b1fdba15c8bfb494f9cf0ef4190a8c2ba6073467bd9d6ed60bd207a05096</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>SECONDS_UNITS</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac33d2b1fdba15c8bfb494f9cf0ef4190a34953c474698c4f3087532ed910169a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>HERTZ_UNITS</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac33d2b1fdba15c8bfb494f9cf0ef4190a24ebb6fb02d0d18316920fe75d4f1360</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RADIANS_UNITS</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac33d2b1fdba15c8bfb494f9cf0ef4190a788009337d13367c776b4c7a6e39ed93</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DEGREES_UNITS</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac33d2b1fdba15c8bfb494f9cf0ef4190a813b08eb76365a54ce935e4add28acab</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>OHMS_UNITS</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac33d2b1fdba15c8bfb494f9cf0ef4190a3f0e5aed9ad87d80aea38ee0139e9c29</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>SIEMENS_UNITS</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac33d2b1fdba15c8bfb494f9cf0ef4190ae756920478732860b23c6c1f3e6d3aac</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>WATTS_UNITS</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac33d2b1fdba15c8bfb494f9cf0ef4190af380a68b72c7642fdb9a1be1554a30ef</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DECIBELS_UNITS</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac33d2b1fdba15c8bfb494f9cf0ef4190a5159d6c3439081182324a3ac305c9bff</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DECIBEL_WATTS_UNITS</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac33d2b1fdba15c8bfb494f9cf0ef4190a8b519c16109d150640201f28c75bf91b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DECIBEL_MILLIWATTS_UNITS</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac33d2b1fdba15c8bfb494f9cf0ef4190aa8930c6544397269ee73b3ffbf82a84a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>SiPrefix</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9fb89ac56439ffc23c8e6942859ec3a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>TERA_PREFIX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9fb89ac56439ffc23c8e6942859ec3a6abd2b1d2aa49f93b8bb9585f83f830c18</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>GIGA_PREFIX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9fb89ac56439ffc23c8e6942859ec3a6a4dcaea62ac4bee447d5d5b0eeee87770</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>MEGA_PREFIX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9fb89ac56439ffc23c8e6942859ec3a6a1166811762516c7bf555accfd483d91d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>KILO_PREFIX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9fb89ac56439ffc23c8e6942859ec3a6a504c282f744bd1d83885ef547f9b6a19</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>NO_PREFIX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9fb89ac56439ffc23c8e6942859ec3a6ad8778d3390d2e20fcca92c8ef72a0903</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>MILLI_PREFIX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9fb89ac56439ffc23c8e6942859ec3a6ab7fe26f03d240b87584fe58c3adddd5e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>MICRO_PREFIX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9fb89ac56439ffc23c8e6942859ec3a6ac7dcf5de2e3b0e04a1ac04e68646b577</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>NANO_PREFIX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9fb89ac56439ffc23c8e6942859ec3a6a72d3a6356c1d49aa03a468f5405d95cb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>PICO_PREFIX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9fb89ac56439ffc23c8e6942859ec3a6a188b3047795515d3a4fb1b55efc90b7e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>FEMTO_PREFIX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9fb89ac56439ffc23c8e6942859ec3a6abcb0295886c8a661c7841bd1ce92c7aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>RscCalibrationState</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>af41cc467667b3529f0b37438ed69b083</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>AF_RSC_CAL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>af41cc467667b3529f0b37438ed69b083af18952b7bf991ff22d53a70cc8e9268e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>FULL_RSC_CAL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>af41cc467667b3529f0b37438ed69b083aec9b8adfde0d2a94f3190a1c91c938eb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>OFF_RSC_CAL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>af41cc467667b3529f0b37438ed69b083ae5c4cfb9e9057bd9b3ecf4b9019b5ab3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>OFS_RSC_CAL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>af41cc467667b3529f0b37438ed69b083af1bf8db61bccc119314b47953b5388b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>RscModel</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4588f1880198c2106f18c903b6cb867b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RSC_02_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4588f1880198c2106f18c903b6cb867ba771d457554410c47eab728f2388217a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RSC_03_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4588f1880198c2106f18c903b6cb867bab6f053e7d24881f5a341eab2501b39e8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RSC_04_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4588f1880198c2106f18c903b6cb867ba0779cc9bc53e49651cbbf3a21e8d0876</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RSC_05_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4588f1880198c2106f18c903b6cb867ba4f6fe4aa89f08f5cf920d131cb542f9e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RSC_13_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4588f1880198c2106f18c903b6cb867ba6539fb0eb56784c1ad59e3882c924592</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RSC_14_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4588f1880198c2106f18c903b6cb867ba3a6df23307335cd02666a9d7941e168f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RSC_15_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4588f1880198c2106f18c903b6cb867ba15dca0b9be137e75c40cc1297328216f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RSC_Z405_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4588f1880198c2106f18c903b6cb867ba59263d2fc57cba1d6ddd281bd2369137</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RSC_Z675_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4588f1880198c2106f18c903b6cb867baf2f9222a8fdfc1754aeb8ea75dd5ee8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RSC_UNKNOWN_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4588f1880198c2106f18c903b6cb867bafe0bc45ee49148b564887d252c0b8cbe</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>VnaCalType</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aed14be025d3f2c7af72c62ee0e516cb3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>OSM_CAL_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aed14be025d3f2c7af72c62ee0e516cb3a554dfea4df7807e32e2bccab7f2f4ed9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>TOSM_CAL_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aed14be025d3f2c7af72c62ee0e516cb3a6345cb79364488133bf14a315d43d066</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>UOSM_CAL_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aed14be025d3f2c7af72c62ee0e516cb3adabb6aa8b6c33457e170fe67804562a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>VnaStandardType</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>OPEN_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aad716b85e0fcce01ecaf5c55a4a231203</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>SHORT_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aa4b7003004c7e0cf81631bc508559c26c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>OFFSET_SHORT_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aa62a71c7de147c37857281397efa8b58b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>OFFSET_SHORT2_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aae0c01dd6eee34f1cb7a6b997194e4e04</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>OFFSET_SHORT3_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aab7dc1b42121f8ed9838140913fcfe648</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>MATCH_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aa7bc1a902cca4bcec506dffb1cb1b164c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>SLIDING_MATCH_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aa7af320277cdd677322c64b1e5e63665d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>REFLECT_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aaf420b8b1a8320d2ce4b9168d93d1b6b7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>THRU_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aaf133c2cfb6637b93f572499a25cb82f7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>LINE_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aa3519843846cbff68f1074c676668c0cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>LINE2_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aacd137ddbb43287a71624dca6024fd3a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>LINE3_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aa7f2b1a3fc142f96da46d0a24ef8ab817</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ATTENUATION_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aaa9241aa03e902432d4a7d210120a72ee</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>SYMMETRIC_NETWORK_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aaee85c74e67a617084ae74c4bd185eb64</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>UNKNOWN_STANDARD_TYPE</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9ca463a100aad8f02e3d00baf761ff7aaba2dfb4dbc1f82f097268452c8b2e03d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>VnaSweepType</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a741a7a035d77e272e364af0697633c79</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>LINEAR_SWEEP</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a741a7a035d77e272e364af0697633c79ad061837f35d10d8b5eedb02b431a371d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>LOG_SWEEP</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a741a7a035d77e272e364af0697633c79a10cce66a1b3df251d7fbb11fd3b89d4c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>SEGMENTED_SWEEP</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a741a7a035d77e272e364af0697633c79a33f403a42a3aea0a67b63aec71da4836</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>POWER_SWEEP</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a741a7a035d77e272e364af0697633c79ad65f8c78351e3522fde3b5b8cb3d64a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>CW_SWEEP</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a741a7a035d77e272e364af0697633c79a72213c41d7382ad523167396ac788a40</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>TIME_SWEEP</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a741a7a035d77e272e364af0697633c79a62d23a952416a66f3d5a072bc9ced1f2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>VnaDirectory</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4af5109825e24daf9ac1de596dc44850</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DEFAULT_DIRECTORY</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4af5109825e24daf9ac1de596dc44850aba70ab56c8497a5155e06e7bc42b3ec7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>EMBED_DIRECTORY</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4af5109825e24daf9ac1de596dc44850ac3bdae926d1a34444e8fa1441525fe32</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DEEMBED_DIRECTORY</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4af5109825e24daf9ac1de596dc44850ade6246814a395c7ccef887fc7c30a9c2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>CAL_GROUP_DIRECTORY</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4af5109825e24daf9ac1de596dc44850aeeb197361de055a6fe6523e31cc3f081</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>CAL_KIT_DIRECTORY</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4af5109825e24daf9ac1de596dc44850a981832126da42584e99723f632952208</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>EXTERNAL_TOOLS_DIRECTORY</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4af5109825e24daf9ac1de596dc44850a1fb38160435656bb12debb661fe4b555</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RECALL_SETS_DIRECTORY</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4af5109825e24daf9ac1de596dc44850a6d5ca8263124d28188c8bdf85edc0d65</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>TRACES_DIRECTORY</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4af5109825e24daf9ac1de596dc44850a9f9f8a45c0bcdf2c9ec7aad9c02ab60d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>VnaModel</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad855d80aa0cfd97d333966940fa8ea01</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ZVA_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad855d80aa0cfd97d333966940fa8ea01a2d51e423a09a3c2b3153aa2cea9a598c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ZVB_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad855d80aa0cfd97d333966940fa8ea01a5da95a0c91001bfb794b9b94965535ac</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ZVH_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad855d80aa0cfd97d333966940fa8ea01adba63c59378b92096fab4185be6b9d8d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ZVL_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad855d80aa0cfd97d333966940fa8ea01a1f5f1ba03530b290a088a2f902558de2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ZVT_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad855d80aa0cfd97d333966940fa8ea01a65d730cf6fef22b7c351a5eaf3f1390d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ZNB_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad855d80aa0cfd97d333966940fa8ea01ad2368b2cd5f0cc866f4bce111466684e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ZNBT_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad855d80aa0cfd97d333966940fa8ea01af13fef3f36941ed7498d28362babbb81</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ZNC_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad855d80aa0cfd97d333966940fa8ea01a7066fd4bb8edb717a681bdfa6c8f6960</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ZNP_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad855d80aa0cfd97d333966940fa8ea01a84ddb44271f00d058dbd9a6275361a06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>UNKNOWN_MODEL</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad855d80aa0cfd97d333966940fa8ea01a3f3d79136caf882d83cc87d6b5f5478e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>VnaEmulationMode</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7d4a7e8a70dfbbc32a553dabe2381f4a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>NO_EMULATION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7d4a7e8a70dfbbc32a553dabe2381f4aa1c62780b1b015465ebad1ca53372d23c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>PNA_EMULATION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7d4a7e8a70dfbbc32a553dabe2381f4aa157713b030dfccebbc8a2333fe49c9ca</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>HP_8510_EMULATION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7d4a7e8a70dfbbc32a553dabe2381f4aa738dcbf912d1eab23b3ae0f7ba2e6261</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>HP_8720_EMULATION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7d4a7e8a70dfbbc32a553dabe2381f4aa73c91c970186c6170831e63b1dc29144</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>HP_8753_EMULATION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7d4a7e8a70dfbbc32a553dabe2381f4aab8a7323b95539d70c78068f248e10c6c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>HP_8714_EMULATION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7d4a7e8a70dfbbc32a553dabe2381f4aa1c284ab1efe315e9ff36c97c29e18990</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ZVR_EMULATION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7d4a7e8a70dfbbc32a553dabe2381f4aa9a1fd28ed6cbe66c21b62d5cb5c7b7c5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>HP_8530_EMULATION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7d4a7e8a70dfbbc32a553dabe2381f4aa2f6231df7774966492dc80879e4e4f3f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ENA_EMULATION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7d4a7e8a70dfbbc32a553dabe2381f4aaaf6487e48db7292fc40262e932807261</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>ZVABT_EMULATION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7d4a7e8a70dfbbc32a553dabe2381f4aac08429b0441ae1aca82fff832f5e0552</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>VnaColorScheme</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ae54ff682cf8310c58191f1b6349e09f5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DARK_BACKGROUND</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ae54ff682cf8310c58191f1b6349e09f5ac0208f506c01bf8d6a77ed681d44a376</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>LIGHT_BACKGROUND</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ae54ff682cf8310c58191f1b6349e09f5a99b64d93fc67c275192cf880466350fb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>BLACK_WHITE_OUTLINE_BACKGROUND</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ae54ff682cf8310c58191f1b6349e09f5a407aefbf802d2adb32a015d0e88b630b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>BLACK_WHITE_SOLID_BACKGROUND</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ae54ff682cf8310c58191f1b6349e09f5a1fe79d0781fe8bd380e1a5cd78c3eb46</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>VnaWindowFunction</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ade955acccb31f71d24b4e5458b7b742e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>REGULAR_WINDOW_FUNCTION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ade955acccb31f71d24b4e5458b7b742ea3b58f436f7b0999dbe0f8aa96dc0330e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>HAMMING_WINDOW_FUNCTION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ade955acccb31f71d24b4e5458b7b742ea007b1aba6911a0756f2947be7e9c364a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>HANN_WINDOW_FUNCTION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ade955acccb31f71d24b4e5458b7b742ea33b4bddabfe425dad335558453cb69f7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>BOHMAN_WINDOW_FUNCTION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ade955acccb31f71d24b4e5458b7b742ea685fd608f32061c752bf01044ace1d66</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>DOLPH_CHEBYCHEV_WINDOW_FUNCTION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ade955acccb31f71d24b4e5458b7b742ea747deaadb3f99845690e7e8b8ce0e8c6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>RiseTimeDefinition</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1f109c762bc8b7db640633c8a9b4f5f7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RISETIME_20_TO_80</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1f109c762bc8b7db640633c8a9b4f5f7a5499071d72009edb7df61b9a656215f8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RISETIME_10_TO_90</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1f109c762bc8b7db640633c8a9b4f5f7a81117b8a1f5d9bafbbf95c6bf937dd22</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>VnaReceiver</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a0caf3cd1fce8615b0f926b3320173aa9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RECEIVER_A</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a0caf3cd1fce8615b0f926b3320173aa9a5141c5dc95df12f1f9fe8d37b6e345f8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <type>@</type>
      <name>RECEIVER_B</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a0caf3cd1fce8615b0f926b3320173aa9a9884a31097eeb934843ac3eeab240dce</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>acc3af340369d563a1bb92e769ebedc86</anchor>
      <arglist>(ConnectionType connection_type)</arglist>
    </member>
    <member kind="function">
      <type>ConnectionType</type>
      <name>toConnectionType</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aedec38fe38dd15d5baf70ec815e3ccf1</anchor>
      <arglist>(QString scpi)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toVnaScpi</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a446bd0db61f520263d5256575d50061a</anchor>
      <arglist>(BalancedPortType type)</arglist>
    </member>
    <member kind="function">
      <type>ConnectorType</type>
      <name>toConnectorType</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a91952c11059e91bb6cd936f1ffe21dbe</anchor>
      <arglist>(QString vnaScpi)</arglist>
    </member>
    <member kind="function">
      <type>ConnectorGender</type>
      <name>toConnectorGender</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa2dc370e5ebc2e8481399159dbef53d3</anchor>
      <arglist>(QString vnaScpi)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toVnaScpi</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac578a630fbf7237a4ceaf8cac27c348f</anchor>
      <arglist>(ConnectorType type)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toVnaScpi</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a55ab29afe3fcf57a574c2ab447c51ddd</anchor>
      <arglist>(ConnectorGender gender)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toConnectorTypeVnaScpi</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a630392534737342a787ace57db99cc3a</anchor>
      <arglist>(Connector connector)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toConnectorGenderVnaScpi</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a876586e0da3223689989d9cd201f9b4d</anchor>
      <arglist>(Connector connector)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac07e397ef61e2ad3de0d5df7e7d787f0</anchor>
      <arglist>(const Connector &amp;left, const Connector &amp;right)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a97ed153c57306b1dc6d17adfe6efcc57</anchor>
      <arglist>(const Connector &amp;left, const Connector &amp;right)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>bValue</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a42ad7834b66ba0f4eb681fa4168a6f8d</anchor>
      <arglist>(double x1, double y1, double x2, double y2)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>bValues</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a3f8487bbaf6e2ec148233a4d6576dae6</anchor>
      <arglist>(QRowVector x, QRowVector y)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>weightedAverage</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7d5e90c7a05fed784ef929a46d58ee98</anchor>
      <arglist>(QRowVector values, QRowVector weights)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>toDouble</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a5e75a474c2f8ba5242fce4450dcce623</anchor>
      <arglist>(SiPrefix prefix)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>acbf9cedf585f787735a12fb954f32f84</anchor>
      <arglist>(ComplexFormat format)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a401f7fe87f90c5ca198323624136aad1</anchor>
      <arglist>(NetworkParameter parameter)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a2fbaebec0acf687c84979be06d132207</anchor>
      <arglist>(NetworkParameter parameter, uint outputPort, uint inputPort)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a91578283cbe5524cd256ae631d7614e5</anchor>
      <arglist>(SiPrefix prefix)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a2b7097a8be97e531c5cffc1ec66b8f8a</anchor>
      <arglist>(Units units)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>abddef2d0ac592f2c9bd33cdbb2f70549</anchor>
      <arglist>(SiPrefix prefix, Units units)</arglist>
    </member>
    <member kind="function">
      <type>SiPrefix</type>
      <name>toSiPrefix</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aef3265ac085cb4b9c3123482a618dc6d</anchor>
      <arglist>(QString prefix)</arglist>
    </member>
    <member kind="function">
      <type>SiPrefix</type>
      <name>getPrefix</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1f7da27811bba5dc59af9872c72b5238</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>AppendPath</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa5cb97be2bab893b0072136464fbbf23</anchor>
      <arglist>(QDir path, QString filename)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>AppendCurrentDirectory</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a56aa4142e468fd8422c87332b23a297f</anchor>
      <arglist>(QString filename)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>GetAppDataPath</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>af57d5ee3608f72345359f9fe53e65e66</anchor>
      <arglist>(QString program_folder)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>AppendAppDataPath</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a05cc3717c6e3f03bb1cc84fae5b3a053</anchor>
      <arglist>(QString program_folder, QString filename)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toScientificNotation</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>af1a4280bf5e6d3cba3f29e11cfad6772</anchor>
      <arglist>(double value, int decimal_places, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>formatValue</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a78777ebbbe7e2f270250983693a54f57</anchor>
      <arglist>(double value, int decimal_places, Units units, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>formatDouble</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4f6310dc021758e8f2015b3e50d26591</anchor>
      <arglist>(double value, int decimal_places)</arglist>
    </member>
    <member kind="function">
      <type>QStringList</type>
      <name>toStringList</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a43e55b9319f66b66baaa2f8841e999f7</anchor>
      <arglist>(QVector&lt; T &gt; vector)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1ff4b93281f6f785d0636ec89688d423</anchor>
      <arglist>(QVector&lt; T &gt; vector, QString separator)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4c251188f7653030333b2dbca1bafe2d</anchor>
      <arglist>(QStringList list, QString separator)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a367a66470f1261677697344ca31223b0</anchor>
      <arglist>(ComplexRowVector vector, QString list_separator, QString format=&quot;(%1, %2)&quot;)</arglist>
    </member>
    <member kind="function">
      <type>QStringList</type>
      <name>portLabels</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac8b87f32bdc28e2626225c2e2f1320aa</anchor>
      <arglist>(QVector&lt; uint &gt; ports)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>portString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a59270a806ff441a388b4abf455af0e6d</anchor>
      <arglist>(QVector&lt; uint &gt; ports)</arglist>
    </member>
    <member kind="function">
      <type>QStringList</type>
      <name>channelLabels</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa3b8d08858b7f4cb6f24de1c124a94eb</anchor>
      <arglist>(QVector&lt; uint &gt; channels)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; uint &gt;</type>
      <name>parseUints</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>abb3ddaa4e84753ac45836e592feb3e93</anchor>
      <arglist>(QString values, QString separator, QString ignore=&quot;&quot;)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; int &gt;</type>
      <name>parseInts</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a8c6a37d918959daf948d92f5957c4b6b</anchor>
      <arglist>(QString values, QString separator, QString ignore=&quot;&quot;)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>parseDoubles</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a97ba76e16afd9853c7a81a6300db5cbe</anchor>
      <arglist>(QString values, QString separator, QString ignore=&quot;&quot;)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>parseComplex</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ab6a9bd540b8f1e2e4ea5bc7e08b4f01b</anchor>
      <arglist>(QString values, QString separator, QString ignore=&quot;&quot;)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>parseComplex</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a257ef823691cebf05e5b8f223b5d9b0b</anchor>
      <arglist>(QRowVector values)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>parseQRowVector</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1d3d8cb2376dd1beb46014ac96b59b60</anchor>
      <arglist>(QString buffer)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>parseQRowVector</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a0f00ddf7ecf4d2c63237fc41036fa7db</anchor>
      <arglist>(ComplexRowVector values)</arglist>
    </member>
    <member kind="function">
      <type>QByteArray</type>
      <name>toBlockDataFormat</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a74dbc88890beeca8ae8c7b2bb5840737</anchor>
      <arglist>(QRowVector values)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>toQRowVector</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7ac15524e43d1d695ecd4adbeb9bd242</anchor>
      <arglist>(QByteArray blockData)</arglist>
    </member>
    <member kind="function">
      <type>QByteArray</type>
      <name>toBlockDataFormat</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4c977f59cee987da721313140ff98d09</anchor>
      <arglist>(ComplexRowVector values)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>toComplexRowVector</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a095d2fe4ee83260c30082bb62657eeb8</anchor>
      <arglist>(QByteArray blockData)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>toDb</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a90325e3eee0931db9b03e33bd969e1ba</anchor>
      <arglist>(double magnitude)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>toDb</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a8b5fac37bd7f5d387e1fbaed38da99b6</anchor>
      <arglist>(QRowVector magnitudes)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>toDb</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aed23023feacd7e66ba8f332cd73a929a</anchor>
      <arglist>(ComplexDouble complexValue)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>toDb</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1d980b57236be3867233edbeca770a9e</anchor>
      <arglist>(ComplexRowVector complexValues)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>toMagnitude</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7a6ebb9f84519ca70bfdcd06a5c6e6cf</anchor>
      <arglist>(double decibels)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>toMagnitude</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a12f7bf7c929558a1234d5d92981059b6</anchor>
      <arglist>(ComplexDouble complexValue)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>toMagnitude</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a85bc362fbb015bcc9d7f4dee551f3ae6</anchor>
      <arglist>(QRowVector values_dB)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>toMagnitude</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac3bb953d5466cb4eb121671c6e5f965b</anchor>
      <arglist>(ComplexRowVector complexValues)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>degrees</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac2ee607bb77fc38d0a66d81a561d2c82</anchor>
      <arglist>(double phase_rad)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>degrees</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad9fad2c39c10c26ee64a498425585e0a</anchor>
      <arglist>(QRowVector phases_rad)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>angle_deg</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a16ffbeaf48af6a84d250a4b6ed08cfbf</anchor>
      <arglist>(ComplexDouble complexValue)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>angle_deg</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac4a1f133e1ad088653bf76c1cffbd8a4</anchor>
      <arglist>(ComplexRowVector complexValues)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>radians</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a43ada3b27897583fde5a568906a41c0c</anchor>
      <arglist>(double phase_deg)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>radians</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a57f7b6fdcaf0ee08f50bd5d6cef201b3</anchor>
      <arglist>(QRowVector phases_deg)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>angle_rad</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aeb448e4e152415694b361688b51757fe</anchor>
      <arglist>(ComplexDouble complexValue)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>angle_rad</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a36d93e3f76c6602b9959bb5171486b70</anchor>
      <arglist>(ComplexRowVector complexValues)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>toVswr</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ae59989515f7fd67a3d5b0988a7325a14</anchor>
      <arglist>(double magnitude)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>toVswr</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1a9c7d9d7aa4cffa3fd95574d23981f8</anchor>
      <arglist>(QRowVector magnitudes)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>toVswr</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a100fb849363ad7d9b7df0e2c31de544a</anchor>
      <arglist>(ComplexDouble complexValue)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>toVswr</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afe11daae4102f507f083c07b47d44b63</anchor>
      <arglist>(ComplexRowVector complexValues)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>real</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad8addfeea470bb836f4ccdbbe5457e9f</anchor>
      <arglist>(ComplexRowVector complexValues)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>imaginary</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a8aa532707d4fbf883ce23b23b895846b</anchor>
      <arglist>(ComplexRowVector complexValues)</arglist>
    </member>
    <member kind="function">
      <type>ComplexDouble</type>
      <name>fromRealImag</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a5f96f507a98b20424a6d5f0f077935b5</anchor>
      <arglist>(double real, double imag)</arglist>
    </member>
    <member kind="function">
      <type>ComplexDouble</type>
      <name>fromMagDegrees</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a2910b66fdecb1db3c45def9b20416ffa</anchor>
      <arglist>(double magnitude, double angle_deg)</arglist>
    </member>
    <member kind="function">
      <type>ComplexDouble</type>
      <name>fromDbDegrees</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4051a16c1fec914796d0e1c033216ed2</anchor>
      <arglist>(double dB, double angle_deg)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; int &gt;</type>
      <name>range</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9f9040fbb1ba563ada8f3e293fcb325d</anchor>
      <arglist>(int start, int stop, int stepSize=1)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; uint &gt;</type>
      <name>range</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aba29c509dc659952d0784be2653e58ad</anchor>
      <arglist>(uint start, uint stop, uint stepSize=1)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>linearSpacing</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa06a5b0c1beff543070e85ef69cfca1c</anchor>
      <arglist>(double start, double stop, int points)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>linearSpacing</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a62a922faa3d1fa360e6c10c5834ab6b1</anchor>
      <arglist>(QRowVector &amp;result, double start, double stop, int points)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>linearSpacing</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>acb477457f800e6528ebe51e7b77388f9</anchor>
      <arglist>(RowVector &amp;result, double start, double stop, int points)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logSpacing</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa6a6dc53ed0a3aeb7b13422f48a792c3</anchor>
      <arglist>(QRowVector &amp;result, double start, double stop, int points)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isInfinity</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a82d846558217ee9aa87a8fe9fb74024a</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotInfinity</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a5b2f17251e538bec30ab06a564e54be3</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNaN</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a2da3316cdc0d9f30d9b7c19e796191da</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotNaN</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>adbed0f7d690e0553b77c42fd0e3960bf</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>roundInf</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a82406f77f81e29888d7c1d0fc6cb90c3</anchor>
      <arglist>(double value, double toValue=DBL_MAX)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>roundInf</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1609c2b05d77afbc01574aa730802758</anchor>
      <arglist>(QRowVector values, double toValue=DBL_MAX)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>round</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ab064c7a47b8e780e57f6df879cf16076</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>round</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>abfb90b6522dc506a85602ab8ecd47270</anchor>
      <arglist>(double value, uint decimal_places)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>floor</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac10aef7f1e85aca6030e5eeec0e5e1d4</anchor>
      <arglist>(double value, double interval)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>ceiling</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a01171a0778b6254c6e4484061c2447ff</anchor>
      <arglist>(double value, double interval)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>roundAxis</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afb5aace1130c30638a96cf43ad35db87</anchor>
      <arglist>(double min, double max, double interval, double &amp;axis_min, double &amp;axis_max)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>roundAxis</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ae9aac1d46b78292370d33f0a73891042</anchor>
      <arglist>(QRowVector values, double interval, double &amp;axis_min, double &amp;axis_max)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>roundAxis</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a74089e52a82669ed232297f52369b532</anchor>
      <arglist>(RowVector values, double interval, double &amp;axis_min, double &amp;axis_max)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>linearInterpolateX</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aea56743d85a9d5f085a61d121659a0fd</anchor>
      <arglist>(double x1, double y1, double x2, double y2, double y_desired)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>linearInterpolateY</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a12bd990ca41ec3647a7c1b183cebed50</anchor>
      <arglist>(double x1, double y1, double x2, double y2, double x_desired)</arglist>
    </member>
    <member kind="function">
      <type>ComplexDouble</type>
      <name>linearInterpolateY</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ab643f9391face07b2757327ced1ec1b5</anchor>
      <arglist>(double x1, ComplexDouble y1, double x2, ComplexDouble y2, double x_desired)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>exp</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa4c85985ac0b1e775a67cb80a5d91029</anchor>
      <arglist>(ComplexRowVector x)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>sum</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1bc51eb7992dcfc1a84d5b70b80e754c</anchor>
      <arglist>(QRowVector x)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>diff</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aac3484c9070dd5a7491e6a31ffe755d1</anchor>
      <arglist>(QRowVector x)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>mod</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aaa0a9a7f90355c93c633892b791f954d</anchor>
      <arglist>(QRowVector x, double denominator)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>cumulativeSum</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a158966986ea84b4b72674ee0b7888be7</anchor>
      <arglist>(QRowVector x)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>arg</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a283f78093d2c8cdc8f295f5391228250</anchor>
      <arglist>(ComplexRowVector x)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>wrap</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1de101bc43524b31d4b99d056796a79f</anchor>
      <arglist>(double x, double bounds=2.0 *PI)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>wrap</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa963d727897de9ddf14b8c64a7946da0</anchor>
      <arglist>(QRowVector x, double bounds=2.0 *PI)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>unwrap</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a48bc89f06f044b86c3cb890b5a565090</anchor>
      <arglist>(QRowVector x, double bounds=2.0 *PI)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>phaseAtDc_rad</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a2cbe6bcaeb53d68b19eca6f9166359e1</anchor>
      <arglist>(QRowVector x, ComplexRowVector y)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>phaseAtDc_deg</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad9627b876d217d16ba9fa9529fc0deae</anchor>
      <arglist>(QRowVector x, ComplexRowVector y)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>fixPhaseAtDc</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7f069a567159a5a555ce74de827e7f61</anchor>
      <arglist>(QRowVector x, ComplexRowVector y)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>addPropagate</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a36dfd672c3e5e7469627e20af0297424</anchor>
      <arglist>(QRowVector x, int startIndex, double value)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>subtractPropagate</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aab674d0683402508336c09eee11263ba</anchor>
      <arglist>(QRowVector x, int startIndex, double value)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>sqrt</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a108ee276905f6053f18adbdd8c4f1bf7</anchor>
      <arglist>(ComplexRowVector x)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>smoothSqrt</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a34accb03cadb6e22e40e87bd033d447f</anchor>
      <arglist>(ComplexRowVector x)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>smoothPhase</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad35bef2369fdf259206c950568378ff9</anchor>
      <arglist>(ComplexRowVector x)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>conjugate</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a32cbf8a3eea06963782d7c82490838a5</anchor>
      <arglist>(ComplexRowVector x)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>multiply</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a44eb6477e388c2a28053326b8f4c4cc1</anchor>
      <arglist>(ComplexRowVector vector, double scalar)</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix2D</type>
      <name>multiply</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>adf5a3ca95570a11e958c6a487550717b</anchor>
      <arglist>(ComplexMatrix2D matrix, double scalar)</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix3D</type>
      <name>multiply</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>abcd3107aa8f1ceed0ca6ec2207861be7</anchor>
      <arglist>(ComplexMatrix3D matrix, double scalar)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>multiply</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a93fdb05e9ed1fae791ef170ea3a9e1a9</anchor>
      <arglist>(QRowVector vector, ComplexDouble scalar)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>multiply</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a2bc8edeadc8825a1356d4be9eac1dd67</anchor>
      <arglist>(ComplexRowVector vector, ComplexDouble scalar)</arglist>
    </member>
    <member kind="function">
      <type>RowVector</type>
      <name>multiply</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a39d6fdfe572189b4b543ed2c1fe68add</anchor>
      <arglist>(RowVector vector, double scalar)</arglist>
    </member>
    <member kind="function">
      <type>Matrix2D</type>
      <name>multiply</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aff7d9037a1da9d6b6e7e8c23ed9ebf8a</anchor>
      <arglist>(Matrix2D matrix, double scalar)</arglist>
    </member>
    <member kind="function">
      <type>Matrix3D</type>
      <name>multiply</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>acf02aaac2d28bfcc353b1056b92a20b0</anchor>
      <arglist>(Matrix3D matrix, double scalar)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>multiply</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ab83b504dfc81911d54b73beedc2d5fc3</anchor>
      <arglist>(QRowVector vector, double scalar)</arglist>
    </member>
    <member kind="function">
      <type>QMatrix2D</type>
      <name>multiply</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>acbab33a3bf448153fd77fae10488d89d</anchor>
      <arglist>(QMatrix2D matrix, double scalar)</arglist>
    </member>
    <member kind="function">
      <type>QMatrix3D</type>
      <name>multiply</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a24a3db61cb4b64929a539fc03679195a</anchor>
      <arglist>(QMatrix3D matrix, double scalar)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>multiplyEach</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>adac5ac068e0edcddc335500c81a65748</anchor>
      <arglist>(ComplexRowVector vector1, ComplexRowVector vector2)</arglist>
    </member>
    <member kind="function">
      <type>RowVector</type>
      <name>multiplyEach</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a64e958fd26a01aeabc5568afb033929e</anchor>
      <arglist>(RowVector vector1, RowVector vector2)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>multiplyEach</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a61eafc7a6dae31957c61dfd2836f1287</anchor>
      <arglist>(QRowVector vector1, QRowVector vector2)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>divideEach</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac9649d420706cacda486e6a326b7905b</anchor>
      <arglist>(ComplexRowVector vector1, ComplexRowVector vector2)</arglist>
    </member>
    <member kind="function">
      <type>RowVector</type>
      <name>divideEach</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac6ccb7bd8170214ee3dcc998f42e3db9</anchor>
      <arglist>(RowVector vector1, RowVector vector2)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>divideEach</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a0ada20a8cc8f6b2d1d68ff3ca6b1edbe</anchor>
      <arglist>(QRowVector vector1, QRowVector vector2)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>add</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7eb1bec04e0160d1490483197bfd8bd6</anchor>
      <arglist>(ComplexRowVector vector1, ComplexRowVector vector2)</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix2D</type>
      <name>add</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aeb70d9906255b09caff1fa71426d6646</anchor>
      <arglist>(ComplexMatrix2D matrix1, ComplexMatrix2D matrix2)</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix3D</type>
      <name>add</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7407b694c1bf322461d45217e204b6b8</anchor>
      <arglist>(ComplexMatrix3D matrix1, ComplexMatrix3D matrix2)</arglist>
    </member>
    <member kind="function">
      <type>RowVector</type>
      <name>add</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a73a78c0fecff5f804b088e9fc5b286a3</anchor>
      <arglist>(RowVector vector1, RowVector vector2)</arglist>
    </member>
    <member kind="function">
      <type>Matrix2D</type>
      <name>add</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ac5382071b09bfe5f4bfd6ea42e9f22b0</anchor>
      <arglist>(Matrix2D matrix1, Matrix2D matrix2)</arglist>
    </member>
    <member kind="function">
      <type>Matrix3D</type>
      <name>add</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a31ebf455c15012c311764d743c9e13ec</anchor>
      <arglist>(Matrix3D matrix1, Matrix3D matrix2)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>add</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad19951063015f44edd32dc0013d94cd6</anchor>
      <arglist>(QRowVector vector1, QRowVector vector2)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>add</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1908c3a1b75a5b5c646690cc3fdf4fbc</anchor>
      <arglist>(QRowVector vector, double scalar)</arglist>
    </member>
    <member kind="function">
      <type>QMatrix2D</type>
      <name>add</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a184fe3cc09fc3b4b1418541dfd4e39cf</anchor>
      <arglist>(QMatrix2D matrix1, QMatrix2D matrix2)</arglist>
    </member>
    <member kind="function">
      <type>QMatrix3D</type>
      <name>add</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa8aa4c9635844b040a44c9854c59bbd7</anchor>
      <arglist>(QMatrix3D matrix1, QMatrix3D matrix2)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>subtract</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>af48500405f7d606c8fadfb35a0ddcec2</anchor>
      <arglist>(ComplexRowVector vector1, ComplexRowVector vector2)</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix2D</type>
      <name>subtract</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a84cef2594a805379baa8e0a1df395dc7</anchor>
      <arglist>(ComplexMatrix2D matrix1, ComplexMatrix2D matrix2)</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix3D</type>
      <name>subtract</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad5815ea51d583aed736472f8627df0c6</anchor>
      <arglist>(ComplexMatrix3D matrix1, ComplexMatrix3D matrix2)</arglist>
    </member>
    <member kind="function">
      <type>RowVector</type>
      <name>subtract</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a9a20fcbf652da781fb2fcbbf53e148e8</anchor>
      <arglist>(RowVector vector1, RowVector vector2)</arglist>
    </member>
    <member kind="function">
      <type>Matrix2D</type>
      <name>subtract</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a3a863d164af0e3584db698426bfb0869</anchor>
      <arglist>(Matrix2D matrix1, Matrix2D matrix2)</arglist>
    </member>
    <member kind="function">
      <type>Matrix3D</type>
      <name>subtract</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>af7805c05bdb953b4da6f59a119a802fd</anchor>
      <arglist>(Matrix3D matrix1, Matrix3D matrix2)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>subtract</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>af7ac924bb672e7342c7ba765a39be0f4</anchor>
      <arglist>(QRowVector vector1, QRowVector vector2)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>subtract</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a64bce15fdbba4d707f489d44361234cc</anchor>
      <arglist>(QRowVector vector, double scalar)</arglist>
    </member>
    <member kind="function">
      <type>QMatrix2D</type>
      <name>subtract</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a39f0d94b234b9a99349de41f2b9b74ff</anchor>
      <arglist>(QMatrix2D matrix1, QMatrix2D matrix2)</arglist>
    </member>
    <member kind="function">
      <type>QMatrix3D</type>
      <name>subtract</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a742556b11d5fc4792c002d709cc492fd</anchor>
      <arglist>(QMatrix3D matrix1, QMatrix3D matrix2)</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix2D</type>
      <name>transpose</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aeae8c8fe3a4b7f4451bd51373b6262d6</anchor>
      <arglist>(ComplexMatrix2D matrix)</arglist>
    </member>
    <member kind="function">
      <type>QMatrix2D</type>
      <name>transpose</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aebb27cbadbdfe5fb7ee8a7d904bd592c</anchor>
      <arglist>(QMatrix2D matrix)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>resize</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a6ca04a2d097b31b51db036f57ebba68e</anchor>
      <arglist>(ComplexMatrix2D &amp;matrix, uint rows, uint columns)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>resize</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ab2a8b1446250d8482ca08018f503cfc8</anchor>
      <arglist>(ComplexMatrix3D &amp;matrix, uint dimension1, uint dimension2, uint dimension3)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>serialize</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad52c99a5bd3de773d0b6a6520885f667</anchor>
      <arglist>(ComplexMatrix2D const &amp;matrix)</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix2D</type>
      <name>toComplexMatrix2D</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4b88ff0464ec91ec2b6f53714b1fb8d3</anchor>
      <arglist>(ComplexRowVector const &amp;data, uint rows, uint columns)</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix3D</type>
      <name>toComplexMatrix3D</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a810f041d7d3c1e797b4e6040fe1f6b82</anchor>
      <arglist>(ComplexRowVector const &amp;data, uint dimension1, uint dimension2, uint dimension3)</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix2D</type>
      <name>subsection</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1e8fd01296b09562665ef20f0076c261</anchor>
      <arglist>(ComplexMatrix2D matrix, QVector&lt; uint &gt; rows, QVector&lt; uint &gt; columns)</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix2D</type>
      <name>subsection</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>abae34756352c3e78039a1d936b73e681</anchor>
      <arglist>(ComplexMatrix2D matrix, QVector&lt; uint &gt; indices)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>af1cf69015287759252f8b7e76a326a64</anchor>
      <arglist>(ComplexMatrix2D &amp;matrix, ComplexMatrix2D data, QVector&lt; uint &gt; toRows, QVector&lt; uint &gt; toColumns)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4a82ae7a3e94a94cdae2b3ecd4a80faa</anchor>
      <arglist>(ComplexMatrix2D &amp;matrix, ComplexMatrix2D data, QVector&lt; uint &gt; indices)</arglist>
    </member>
    <member kind="function">
      <type>QMap&lt; T, V &gt;</type>
      <name>cascade</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad53aceeae099578a31d8bd374328d505</anchor>
      <arglist>(QMap&lt; T, U &gt; a, QMap&lt; U, V &gt; b)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>max</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a2daa770aac6dd9e2682dcbd091b3a900</anchor>
      <arglist>(QVector&lt; T &gt; vector)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>max</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a092585c3ac51be4fd2f5890a4f39f797</anchor>
      <arglist>(QVector&lt; T &gt; vector, T &amp;maximum, int &amp;index)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>max</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a14051d4d2caf61e4ff147cdb70e8e49f</anchor>
      <arglist>(std::vector&lt; T &gt; vector)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>max</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a8e90b240b35e29198e213b4f13149b11</anchor>
      <arglist>(std::vector&lt; T &gt; vector, T &amp;maximum, int &amp;index)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>min</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aea9801959ad0df2547ebd0e7e2717c5b</anchor>
      <arglist>(QVector&lt; T &gt; vector)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>min</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aaeab31f23497d4c7f2fb108afbd5e6f8</anchor>
      <arglist>(QVector&lt; T &gt; vector, T &amp;minimum, int &amp;index)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>min</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a388df8a3bb95fba9ed7ff312be73237d</anchor>
      <arglist>(std::vector&lt; T &gt; vector)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>min</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a1e635f140e9a3d386a8ae68d4183ee23</anchor>
      <arglist>(std::vector&lt; T &gt; vector, T &amp;minimum, int &amp;index)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a6187f001c2d47a1bcf7e55fffc3cae75</anchor>
      <arglist>(const IndexName &amp;right, const IndexName &amp;left)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ada8e824ea3f432f40148ecb9848c3ca6</anchor>
      <arglist>(const IndexName &amp;right, const IndexName &amp;left)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a39234bb9350b23a6eb532a9f519a97af</anchor>
      <arglist>(const NameLabel &amp;right, const NameLabel &amp;left)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aa2fa79b0dfe58e581ed5d8784579ac22</anchor>
      <arglist>(const NameLabel &amp;right, const NameLabel &amp;left)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>RscCalState_To_String</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a6c8f7600af906cd94e77e80c918bab6a</anchor>
      <arglist>(RscCalibrationState state)</arglist>
    </member>
    <member kind="function">
      <type>RscCalibrationState</type>
      <name>Scpi_To_RscCalState</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad0161f77d312369c7399d89125ca8266</anchor>
      <arglist>(QString scpi)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>ToString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a3b7200506b30a6eb122bde8bc1449ce0</anchor>
      <arglist>(RscModel model)</arglist>
    </member>
    <member kind="function">
      <type>RscModel</type>
      <name>Scpi_to_RscModel</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a839354e4408d5916cde73829940fce8a</anchor>
      <arglist>(QString scpi)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toScpi</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a6cfc38382274ab6bba34041614b352eb</anchor>
      <arglist>(VnaCalType type)</arglist>
    </member>
    <member kind="function">
      <type>VnaCalType</type>
      <name>toVnaCalType</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a782487130b4a3c995371050f18ef6922</anchor>
      <arglist>(QString scpi)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>sort</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a675e23b9f3e241bdfd17390d9d546bd6</anchor>
      <arglist>(Connector &amp;connector1, Connector &amp;connector2)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>sort</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a62a5d8ec9ef55d57fb000ac213c449b8</anchor>
      <arglist>(ConnectorGender &amp;gender1, ConnectorGender &amp;gender2)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>sort</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a38668f5ffd0a8c1ddfe9008701f66ff3</anchor>
      <arglist>(uint &amp;port1, uint &amp;port2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a3188740f580e8e54d1103d7171c5490b</anchor>
      <arglist>(const VnaCalStandard &amp;right, const VnaCalStandard &amp;left)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>aeae83c95a3ef4810afc15e1c15ca558f</anchor>
      <arglist>(const VnaCalStandard &amp;right, const VnaCalStandard &amp;left)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toScpi</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ab2f2ea0a80a723ce1fdf99d005cb6c98</anchor>
      <arglist>(VnaSweepType sweepType)</arglist>
    </member>
    <member kind="function">
      <type>VnaSweepType</type>
      <name>toVnaSweepType</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a8341063968d06412b1c0713907e13df1</anchor>
      <arglist>(QString scpi)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toString</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a803ac7720b39828537ed067e2e5b1599</anchor>
      <arglist>(VnaModel model)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toSetFileExtension</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>abc530d8cc4fb4af9cbb2b389122b97cd</anchor>
      <arglist>(VnaModel model)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a98f28e7bd9f52e4fda5411eacfd8a98a</anchor>
      <arglist>(VnaStandardModel const &amp;left, VnaStandardModel const &amp;right)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a4bb4255a1505d989988bf4e5bf6968cf</anchor>
      <arglist>(VnaStandardModel const &amp;left, VnaStandardModel const &amp;right)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toScpi</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a5fbe812a0f21ba533aee3717affc28b7</anchor>
      <arglist>(VnaReceiver receiver)</arglist>
    </member>
    <member kind="function">
      <type>VnaReceiver</type>
      <name>toVnaReceiver</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a8d575d47dbb967f85fc36439d58aff23</anchor>
      <arglist>(QString scpi)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toScpi</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a5bc79df0bf071f46c615bc832eec4b72</anchor>
      <arglist>(VnaUserDefinedPort userDefinedPort)</arglist>
    </member>
    <member kind="function">
      <type>VnaUserDefinedPort</type>
      <name>toUserDefinedPort</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>abf29c95c84ba00760dbdb51885aaa2c0</anchor>
      <arglist>(QString scpi)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a88ba0257d35cfbf6aabd3f3d76399374</anchor>
      <arglist>(VnaUserDefinedPort const &amp;left, VnaUserDefinedPort const &amp;right)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>afc8e915bbe9d7bdf5e912927d469ccc7</anchor>
      <arglist>(VnaUserDefinedPort const &amp;left, VnaUserDefinedPort const &amp;right)</arglist>
    </member>
    <member kind="variable">
      <type>const char</type>
      <name>RSA_TOOLBOX_VERSION</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a3b0288a2b3aee0dfa13b36da65e5cfa5</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable">
      <type>const char</type>
      <name>COMPANY_FOLDER</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a84bb6c89cfb4eaf1f998b7ab9a92ab02</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable">
      <type>const double</type>
      <name>PI</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a952eac791b596a61bba0a133a3bb439f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const double</type>
      <name>E</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ab587ba72a9c23f238cb4fd70e2fdb545</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const double</type>
      <name>DBL_INF</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a62ba705fcc7c634064b60d0e973bb853</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const double</type>
      <name>DBL_NEG_INF</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>a7cf1a344b138cc337f4380711deba2f1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const double</type>
      <name>DBL_NAN</name>
      <anchorfile>namespace_rsa_toolbox.html</anchorfile>
      <anchor>ad24e1f6ce807f3a5c245f7ee6e9e8b03</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::BalancedPort</name>
    <filename>class_rsa_toolbox_1_1_balanced_port.html</filename>
    <member kind="function">
      <type></type>
      <name>BalancedPort</name>
      <anchorfile>class_rsa_toolbox_1_1_balanced_port.html</anchorfile>
      <anchor>a3a47c5546649bcd01ec5859e5cb1a041</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>BalancedPort</name>
      <anchorfile>class_rsa_toolbox_1_1_balanced_port.html</anchorfile>
      <anchor>af56577a1d17cd310c888b4a8bc51eba7</anchor>
      <arglist>(uint logicalPort)</arglist>
    </member>
    <member kind="function">
      <type>BalancedPortType</type>
      <name>portType</name>
      <anchorfile>class_rsa_toolbox_1_1_balanced_port.html</anchorfile>
      <anchor>a1135af608c8f168efe6012b0261d7695</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isSingleEnded</name>
      <anchorfile>class_rsa_toolbox_1_1_balanced_port.html</anchorfile>
      <anchor>a934d9bea93f1da3a08c2843585e330de</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isBalanced</name>
      <anchorfile>class_rsa_toolbox_1_1_balanced_port.html</anchorfile>
      <anchor>a09c71d4df079060a8552af0edac962cb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isDifferential</name>
      <anchorfile>class_rsa_toolbox_1_1_balanced_port.html</anchorfile>
      <anchor>a70a8b129aaf4d399f0732e4fa1a9452a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isCommonMode</name>
      <anchorfile>class_rsa_toolbox_1_1_balanced_port.html</anchorfile>
      <anchor>abcd92d101aa0947434a0fd1985435f10</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>logicalPort</name>
      <anchorfile>class_rsa_toolbox_1_1_balanced_port.html</anchorfile>
      <anchor>aff71397e72ae6682f4dde54699b069c2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPortType</name>
      <anchorfile>class_rsa_toolbox_1_1_balanced_port.html</anchorfile>
      <anchor>a76e33d64b7f79256ed2ebee6aae29608</anchor>
      <arglist>(BalancedPortType type)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setSingleEnded</name>
      <anchorfile>class_rsa_toolbox_1_1_balanced_port.html</anchorfile>
      <anchor>af2198b9d35f2e90889b86ce31bc2b351</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDifferential</name>
      <anchorfile>class_rsa_toolbox_1_1_balanced_port.html</anchorfile>
      <anchor>abfce864eecd32e57648c4f17f5042b5f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCommonMode</name>
      <anchorfile>class_rsa_toolbox_1_1_balanced_port.html</anchorfile>
      <anchor>a1e37b0bb3a37177d55b90deb73517509</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setLogicalPort</name>
      <anchorfile>class_rsa_toolbox_1_1_balanced_port.html</anchorfile>
      <anchor>a87ad9f381cec073b96754d885052af37</anchor>
      <arglist>(uint logicalPort)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator int</name>
      <anchorfile>class_rsa_toolbox_1_1_balanced_port.html</anchorfile>
      <anchor>a4f4ea421e40bda08a2deca657f640fea</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator uint</name>
      <anchorfile>class_rsa_toolbox_1_1_balanced_port.html</anchorfile>
      <anchor>a97a032b37cdadc8ac34481c374f9634a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toVnaScpi</name>
      <anchorfile>class_rsa_toolbox_1_1_balanced_port.html</anchorfile>
      <anchor>a4b173b82bb492c5d33570a9b1910cdd1</anchor>
      <arglist>(BalancedPortType type)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::Connector</name>
    <filename>class_rsa_toolbox_1_1_connector.html</filename>
    <member kind="function">
      <type></type>
      <name>Connector</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a98dcfd602309bb9d0757d0a943c97cd2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Connector</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a292a97d5e9207d8aed38b308cf724ef2</anchor>
      <arglist>(const Connector &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Connector</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>ac229bccd1f15a62b2922a7b030562158</anchor>
      <arglist>(ConnectorType type, ConnectorGender gender=MALE_GENDER)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Connector</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>aca86ee25bf97cf7961d8b69e70fe91d3</anchor>
      <arglist>(QString customType, ConnectorGender gender=MALE_GENDER)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>displayText</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a9944fb6e1c6c1323263e37bdba06c2b4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>displayType</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>aec201798cb33fcb3c7dffec7259e0a94</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>displayGender</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a2eb67c0a4ad3eb7300ae2f0eccf849dd</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>genderAbbreviation</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a4f99c475c65fa68f36ce31e83925ffac</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isType</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>ae2322591f8616c98eb3f7d60378026f5</anchor>
      <arglist>(Connector &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotType</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>aa913e97fe035fc677a1888cf4a428f88</anchor>
      <arglist>(Connector &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isCustomType</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a7e962a1151ed339a5571db2ee4f658e7</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotCustomType</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a899c08008b268d15d927564faf92f39d</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isGender</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a6a72a4731f22fc54b667979d05a05b5a</anchor>
      <arglist>(ConnectorGender gender) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isMale</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>aebd8639c0076439cdc71eeac6c84c02f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotMale</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a005de4031172b7ff3206a0d0ec5f7b13</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isFemale</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>ac732e2378747c65b5ba737fe9c2c74e2</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotFemale</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>ac43970e102ac8c4504a34c51cb8abbe6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isGenderNeutral</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>ab327a2e06d17572630c9621b0c91e425</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isGenderSpecific</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a027b98434800338f77ba57384afc63da</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>ConnectorType</type>
      <name>type</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a6cec727537aad692bfc4d1f2e55cce7d</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>customType</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a0a0b5dae45b502609aa24858979a38f9</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>ConnectorGender</type>
      <name>gender</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>afbe0331cca4e8a65607c498ecb01ea60</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>Connector</type>
      <name>getMatingConnector</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>aff1f136213e085e4e902d5d18e308694</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setType</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>ae90ee028f0f690616502a8a3631dcdd9</anchor>
      <arglist>(const Connector type)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setType</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a4431e852532c47c256e4aa8fd1644257</anchor>
      <arglist>(ConnectorType type)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCustomType</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>ad58fb04ba88f5265b906bbfa62022f60</anchor>
      <arglist>(QString type)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setGender</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>ab905388af014c69ca0f2d58c71d9f6e8</anchor>
      <arglist>(ConnectorGender gender)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a65b079a3d13e3033981fa14f302d2685</anchor>
      <arglist>(const Connector &amp;other)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static QStringList</type>
      <name>displayText</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a65e5cdafeb90b94565efaa72060c4ff1</anchor>
      <arglist>(QVector&lt; Connector &gt; connectors)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static QString</type>
      <name>displayType</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a22b97a494ef0325d784b12e3ccdf2841</anchor>
      <arglist>(ConnectorType type)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>isSingleConnectorType</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>aa26b2813671de12c367c7924d9b2abe3</anchor>
      <arglist>(QVector&lt; Connector &gt; &amp;connectors)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static int</type>
      <name>numberOfMaleConnectors</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a908b79608e66e67f78070c0fd8cd73e4</anchor>
      <arglist>(QVector&lt; Connector &gt; &amp;connectors)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static int</type>
      <name>numberOfFemaleConnectors</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a9499788a2bbcfbe897117ccb2fcabd2c</anchor>
      <arglist>(QVector&lt; Connector &gt; &amp;connectors)</arglist>
    </member>
    <member kind="function">
      <type>ConnectorType</type>
      <name>toConnectorType</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a6fd4392a434cd20c2ceca1ce403d64b9</anchor>
      <arglist>(QString vnaScpi)</arglist>
    </member>
    <member kind="function">
      <type>ConnectorGender</type>
      <name>toConnectorGender</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a8ef07f6fc2bb1fd4a622fe136a3095e8</anchor>
      <arglist>(QString vnaScpi)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toVnaScpi</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a577d45acb66cd3cbe8cb6d51fdce3411</anchor>
      <arglist>(ConnectorType type)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toVnaScpi</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>aa2570272aec9074125ef0a8f3d4a0687</anchor>
      <arglist>(ConnectorGender gender)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toConnectorTypeVnaScpi</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a47212519396e7e490efae70fdb25714e</anchor>
      <arglist>(Connector connector)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>toConnectorGenderVnaScpi</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a070da66083caf1fe8b467b8e17dedf51</anchor>
      <arglist>(Connector connector)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a75aebc1f06692c300a43366c89526e8b</anchor>
      <arglist>(const Connector &amp;right, const Connector &amp;left)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>class_rsa_toolbox_1_1_connector.html</anchorfile>
      <anchor>a6d675583a247f0145128be6990b4e2de</anchor>
      <arglist>(const Connector &amp;right, const Connector &amp;left)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::GenericBus</name>
    <filename>class_rsa_toolbox_1_1_generic_bus.html</filename>
    <member kind="slot" virtualness="pure">
      <type>virtual bool</type>
      <name>lock</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>a51cc700e46d567a32975bd705b311264</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="slot" virtualness="pure">
      <type>virtual bool</type>
      <name>unlock</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>acee63855a5fae0b11df91151e9aa768b</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="slot" virtualness="pure">
      <type>virtual bool</type>
      <name>local</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>a7a439487a63a07cb287eb8a8ba65f477</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="slot" virtualness="pure">
      <type>virtual bool</type>
      <name>remote</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>ad3ffbe90d43b7616140ef0e965f92c4c</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="slot" virtualness="pure">
      <type>virtual void</type>
      <name>printStatus</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>adab371fea88c2e8b4d14514fcbb137e3</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="signal">
      <type>void</type>
      <name>error</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>a11ed5d61ec9f8745ef23bf7a4bab4136</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="signal">
      <type>void</type>
      <name>print</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>a2ab94e7fed40714949685d516bc50ff5</anchor>
      <arglist>(QString text) const </arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>GenericBus</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>a5c8dec89cd333703cf8914c235f24314</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>GenericBus</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>ae2b3105bf30de66a056944716c3a2000</anchor>
      <arglist>(ConnectionType connectionType, QString address, uint bufferSize_B=500, uint timeout_ms=1000, QObject *parent=0)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>isOpen</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>ac11fde026ec3cc0fdaaeaa880774ec1a</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isClosed</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>aede4b7e16e8732d29bb13b8fe77573b7</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>ConnectionType</type>
      <name>connectionType</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>aff14cbd4ea9a7272a2965f735773c21f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>address</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>a45ed6612500c0973f68b103afb02e9b5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>bufferSize_B</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>a47e59c061aa54605deba2afffb9a1509</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setBufferSize</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>a94a8164de71f998b98da536ece6f6c39</anchor>
      <arglist>(uint size_B)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>timeout_ms</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>a65900048d44bd8e765de52ea5b22b074</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setTimeout</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>a64f8674ed2fc1bf521b82b2c0523d310</anchor>
      <arglist>(uint time_ms)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>read</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>a71e5fd121c106817d7b2572ed71d321b</anchor>
      <arglist>(char *buffer, uint bufferSize_B)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>read</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>a5e5005e2f7a438e19865ebc36ceaf6d5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>write</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>a5201888c1fe2bad80795fa04db2b59e4</anchor>
      <arglist>(QString scpiCommand)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>query</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>ad4a1fd0b3aed02610fe755ab99368d7f</anchor>
      <arglist>(QString scpiCommand)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>binaryRead</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>a0c5e75f5a0c689d0fbb8c41623e90d91</anchor>
      <arglist>(char *buffer, uint bufferSize_B, uint &amp;bytesRead)</arglist>
    </member>
    <member kind="function">
      <type>QByteArray</type>
      <name>binaryRead</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>ae13a211dade1f3df58ed6e5f00a7be1a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>binaryWrite</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>a7aa8d5adf09f1b56bc9577bbddffcc42</anchor>
      <arglist>(QByteArray scpiCommand)</arglist>
    </member>
    <member kind="function">
      <type>QByteArray</type>
      <name>binaryQuery</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>a4fd7dc0b8f616f16632ef15fd9cfd986</anchor>
      <arglist>(QByteArray scpiCommand)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual bool</type>
      <name>_read</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>a9b42ece7656e081a99b2712c0f722c4e</anchor>
      <arglist>(char *buffer, uint bufferSize)=0</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual bool</type>
      <name>_write</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>a2b3454e0d08ee05ea4cba44c83222c3e</anchor>
      <arglist>(QString scpiCommand)=0</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual bool</type>
      <name>_binaryRead</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>a242f67a055440463cc7b61068793dabc</anchor>
      <arglist>(char *buffer, uint bufferSize, uint &amp;bytesRead)=0</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual bool</type>
      <name>_binaryWrite</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>a98c33a8d19eff1cee007c98b5d63a73d</anchor>
      <arglist>(QByteArray scpiCommand)=0</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ConnectionType</type>
      <name>_connectionType</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>ab56073dcf5f6af1685778e06d64bc893</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QString</type>
      <name>_address</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>a93022a36d845ee4a72d1c4c73ecc33f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>uint</type>
      <name>_bufferSize_B</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>ab4247e4664aad376a5eacffcd3250c81</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>uint</type>
      <name>_timeout_ms</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>a86a1e0018232f5b4b499e070813333ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QScopedArrayPointer&lt; char &gt;</type>
      <name>_buffer</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_bus.html</anchorfile>
      <anchor>afd8a599827f7ef3e2c61f4d709361578</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::GenericInstrument</name>
    <filename>class_rsa_toolbox_1_1_generic_instrument.html</filename>
    <member kind="slot">
      <type>bool</type>
      <name>lock</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>abde223cb8968835b7f8f060e505facc2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>bool</type>
      <name>unlock</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>ae399421ee39cae4df5ea44bd21e31254</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>bool</type>
      <name>local</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>ae4642a972205ef378bb3a1550a8418d8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>bool</type>
      <name>remote</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a6f0890ff36c5a5fb58cdaca77e3f15f9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>preset</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>ae1f5fa51408b7ea44b4a8cc980693b1b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>clearStatus</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a904a80a9a54910609e8c76caa913159e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="signal">
      <type>void</type>
      <name>busError</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a542c3f4d09b418e2a9bccd73d00e1ba3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="signal">
      <type>void</type>
      <name>connected</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a5311a75dc2e16ac36238d0abcc02e7b4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="signal">
      <type>void</type>
      <name>disconnected</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a2f1c33b2c7f009b786fa5799313c59ec</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>GenericInstrument</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a83b74205cd1cba0e321f9a4c00e4ef08</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>GenericInstrument</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a34a5ed84dc044bc5e33a330e033d1cd1</anchor>
      <arglist>(GenericBus *bus, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>GenericInstrument</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>aa20f4d8867c2994c1d682c0fec13042c</anchor>
      <arglist>(ConnectionType type, QString address, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>ConnectionType</type>
      <name>connectionType</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>aff14cbd4ea9a7272a2965f735773c21f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>address</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a45ed6612500c0973f68b103afb02e9b5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isConnected</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a180fa55a4bf36580963bed9e3e09c227</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isDisconnected</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a370be337417c7101d85ca7a67ef21fbb</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isLogOpen</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a4f303390e6468b0d372148aeb633ee60</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isLogConnected</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a5245f03cb1a20a6d8e4f597548ba39da</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isLogDisconnected</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a814dd83a4d865ad04d7e8d9290830e11</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isRohdeSchwarz</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a5208c42f7becd9a076b17c288c0700f9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>idString</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a9d5cd7c546877d3571965055fe5135ab</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>optionsString</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>abd432a2a6aed6d74b9563d965d9e5a01</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Log *</type>
      <name>log</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a771abc4a471f6d3dc48ba2e3e9905c33</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>useLog</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>ab3a9f1bec710e3bdc3e65e4e555b6a70</anchor>
      <arglist>(Log *log)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>disconnectLog</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a20c5b46b1404c1aa9d431080a55bdf70</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>print</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a9fcecd48b86862430fa0a6f25c9ba139</anchor>
      <arglist>(QString text)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>printLine</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a84aed46379d2dc33df360025cb2d15b4</anchor>
      <arglist>(QString text=&quot;&quot;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>printInfo</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a2dbaf5580b5305d54cff6848ae7deb30</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>printInfo</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>ada409285acc32db14ccc3e8e99beb740</anchor>
      <arglist>(QTextStream &amp;stream)</arglist>
    </member>
    <member kind="function">
      <type>GenericBus *</type>
      <name>takeBus</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a6dedb1983f0f3bdafb0b0550cdb13371</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>resetBus</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a6978c084f6d48b500720cac6116a3838</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>resetBus</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>ae02f700c85df5209413c4ce67ac32960</anchor>
      <arglist>(GenericBus *bus)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>resetBus</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a1f62a637904b8ef7e00750be9b58229a</anchor>
      <arglist>(ConnectionType type, QString address)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>read</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a4cac74fe8f5d8ba90799cc152760b866</anchor>
      <arglist>(char *buffer, uint bufferSize_B, uint timeout_ms=1000)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>read</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a2e4527a118e4231171c58bf72811b159</anchor>
      <arglist>(uint bufferSize_B=500, uint timeout_ms=1000)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>write</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a5201888c1fe2bad80795fa04db2b59e4</anchor>
      <arglist>(QString scpiCommand)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>query</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>afbbe93ca7111ba0a8382ad95c49247bd</anchor>
      <arglist>(QString scpiCommand, uint bufferSize_B=500, uint timeout_ms=1000)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>binaryRead</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a2a401286ede0b89d0119398fd5569619</anchor>
      <arglist>(char *buffer, uint bufferSize_B, uint &amp;bytesRead, uint timeout_ms=1000)</arglist>
    </member>
    <member kind="function">
      <type>QByteArray</type>
      <name>binaryRead</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>aeb8915dfcd848eef04a69cef41ebcb43</anchor>
      <arglist>(uint bufferSize_B=500, uint timeout_ms=1000)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>binaryWrite</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a7aa8d5adf09f1b56bc9577bbddffcc42</anchor>
      <arglist>(QByteArray scpiCommand)</arglist>
    </member>
    <member kind="function">
      <type>QByteArray</type>
      <name>binaryQuery</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a8bd7dd60c803759cf0ad29894f46bb68</anchor>
      <arglist>(QByteArray scpiCommand, uint bufferSize_B=500, uint timeout_ms=1000)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>wait</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>aa3b21853f890838c88d047d6c2786917</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>pause</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a7167f5c196fc5e167bfabde1a730e81d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>initializePolling</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>a694167390c3e8d1acb16c86d026fabb9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isOperationComplete</name>
      <anchorfile>class_rsa_toolbox_1_1_generic_instrument.html</anchorfile>
      <anchor>acb2283a6cb20418383f3f512caf30550</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::IndexName</name>
    <filename>class_rsa_toolbox_1_1_index_name.html</filename>
    <member kind="function">
      <type></type>
      <name>IndexName</name>
      <anchorfile>class_rsa_toolbox_1_1_index_name.html</anchorfile>
      <anchor>abf42394f2a7c06fde9ae389eb56387fe</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>IndexName</name>
      <anchorfile>class_rsa_toolbox_1_1_index_name.html</anchorfile>
      <anchor>a341a7f514961330f90a86768216ab534</anchor>
      <arglist>(uint index, QString name)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>index</name>
      <anchorfile>class_rsa_toolbox_1_1_index_name.html</anchorfile>
      <anchor>a79f1dec4c0ad25ad2d6d2e30e3d5d152</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>name</name>
      <anchorfile>class_rsa_toolbox_1_1_index_name.html</anchorfile>
      <anchor>a2b0a198f837184bf6fff555cee3ce770</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setIndex</name>
      <anchorfile>class_rsa_toolbox_1_1_index_name.html</anchorfile>
      <anchor>ad615b47b4cea308bf89b82cb840a6c8a</anchor>
      <arglist>(uint index)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setName</name>
      <anchorfile>class_rsa_toolbox_1_1_index_name.html</anchorfile>
      <anchor>a6220fae15759fd0fa7d75e415df34e83</anchor>
      <arglist>(QString name)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_index_name.html</anchorfile>
      <anchor>a376d9fda7125f2e9ed719598997f373b</anchor>
      <arglist>(const IndexName &amp;other)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static QVector&lt; IndexName &gt;</type>
      <name>parse</name>
      <anchorfile>class_rsa_toolbox_1_1_index_name.html</anchorfile>
      <anchor>aab6e708d1a0987c0a2cf09d7f6d96a44</anchor>
      <arglist>(QString list, QString separator)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static QVector&lt; IndexName &gt;</type>
      <name>parse</name>
      <anchorfile>class_rsa_toolbox_1_1_index_name.html</anchorfile>
      <anchor>a98223c979be68ad71285970b26e6d416</anchor>
      <arglist>(QString list, QString separator, QString ignore)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>separate</name>
      <anchorfile>class_rsa_toolbox_1_1_index_name.html</anchorfile>
      <anchor>a4959779ad6823a89d7c041047f923320</anchor>
      <arglist>(QVector&lt; IndexName &gt; indexNames, QVector&lt; uint &gt; &amp;indices, QStringList &amp;names)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static QVector&lt; uint &gt;</type>
      <name>indices</name>
      <anchorfile>class_rsa_toolbox_1_1_index_name.html</anchorfile>
      <anchor>a9846246012a6ee070e7a25dce4eacc07</anchor>
      <arglist>(QVector&lt; IndexName &gt; indexNames)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static QStringList</type>
      <name>names</name>
      <anchorfile>class_rsa_toolbox_1_1_index_name.html</anchorfile>
      <anchor>a091a527049d6073774f8b525fa26f8a8</anchor>
      <arglist>(QVector&lt; IndexName &gt; indexNames)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::Key</name>
    <filename>class_rsa_toolbox_1_1_key.html</filename>
    <member kind="function">
      <type></type>
      <name>Key</name>
      <anchorfile>class_rsa_toolbox_1_1_key.html</anchorfile>
      <anchor>ac37f8f06a27afe358919f282c3bd11d4</anchor>
      <arglist>(QString path)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Exists</name>
      <anchorfile>class_rsa_toolbox_1_1_key.html</anchorfile>
      <anchor>a90fe9b5b26b0a3ab074d9115c748f0b8</anchor>
      <arglist>(QString key)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>DoesNotExist</name>
      <anchorfile>class_rsa_toolbox_1_1_key.html</anchorfile>
      <anchor>a7597608a812960da09075d96512d1191</anchor>
      <arglist>(QString key)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isTrue</name>
      <anchorfile>class_rsa_toolbox_1_1_key.html</anchorfile>
      <anchor>ad1d6d06e7b8419d1f7eb99f1ab79339d</anchor>
      <arglist>(QString key)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isFalse</name>
      <anchorfile>class_rsa_toolbox_1_1_key.html</anchorfile>
      <anchor>ae21ed17914585f5b3ab84dd3ebeb7cb2</anchor>
      <arglist>(QString key)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Get</name>
      <anchorfile>class_rsa_toolbox_1_1_key.html</anchorfile>
      <anchor>a7a691472644d71eb1489d9388179ab8d</anchor>
      <arglist>(QString key, T &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Set</name>
      <anchorfile>class_rsa_toolbox_1_1_key.html</anchorfile>
      <anchor>a65ce1c838291764e0bd796a549ce13e6</anchor>
      <arglist>(QString key, T value)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Delete</name>
      <anchorfile>class_rsa_toolbox_1_1_key.html</anchorfile>
      <anchor>aa28ed71e50c73c8f1cec250388fe769a</anchor>
      <arglist>(QString key)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::Log</name>
    <filename>class_rsa_toolbox_1_1_log.html</filename>
    <member kind="slot">
      <type>void</type>
      <name>open</name>
      <anchorfile>class_rsa_toolbox_1_1_log.html</anchorfile>
      <anchor>a9e8555112049fc2b4945120b3c45f8ab</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>close</name>
      <anchorfile>class_rsa_toolbox_1_1_log.html</anchorfile>
      <anchor>a5ae591df94fc66ccb85cbb6565368bca</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>rename</name>
      <anchorfile>class_rsa_toolbox_1_1_log.html</anchorfile>
      <anchor>ad43c27ec3647ad13f65cbc0f9b04f868</anchor>
      <arglist>(QString pathName)</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>printApplicationHeader</name>
      <anchorfile>class_rsa_toolbox_1_1_log.html</anchorfile>
      <anchor>a78c1c1b3c18cc6f666d4d791cfe9a4cf</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>print</name>
      <anchorfile>class_rsa_toolbox_1_1_log.html</anchorfile>
      <anchor>a9fcecd48b86862430fa0a6f25c9ba139</anchor>
      <arglist>(QString text)</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>printLine</name>
      <anchorfile>class_rsa_toolbox_1_1_log.html</anchorfile>
      <anchor>a52970f561919ea7fec0235179a1f11f9</anchor>
      <arglist>(QString text)</arglist>
    </member>
    <member kind="signal">
      <type>void</type>
      <name>closed</name>
      <anchorfile>class_rsa_toolbox_1_1_log.html</anchorfile>
      <anchor>accc6ef63b2d443dadba71ae080397c0c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="signal">
      <type>void</type>
      <name>opened</name>
      <anchorfile>class_rsa_toolbox_1_1_log.html</anchorfile>
      <anchor>a0fb61747d3f8a3fdc9e593cdc23b0f85</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="signal">
      <type>void</type>
      <name>renamed</name>
      <anchorfile>class_rsa_toolbox_1_1_log.html</anchorfile>
      <anchor>a71cf13198ebe06945acd7f2073d5880e</anchor>
      <arglist>(QString pathName)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Log</name>
      <anchorfile>class_rsa_toolbox_1_1_log.html</anchorfile>
      <anchor>aadbf333826e76693b3326fa60bc803ad</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Log</name>
      <anchorfile>class_rsa_toolbox_1_1_log.html</anchorfile>
      <anchor>ae5cf0e7d024b0b070fb3bd386f526018</anchor>
      <arglist>(QString directory, QString filename, QString applicationName, QString applicationVersion, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~Log</name>
      <anchorfile>class_rsa_toolbox_1_1_log.html</anchorfile>
      <anchor>a4fc4fd3dcde9bf8ba8195c0983fbe21b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isOpen</name>
      <anchorfile>class_rsa_toolbox_1_1_log.html</anchorfile>
      <anchor>a7a8f153459b77aaa1c4486a9f378927b</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isClosed</name>
      <anchorfile>class_rsa_toolbox_1_1_log.html</anchorfile>
      <anchor>a995cd45aacf946ca210491d12ed4a0c0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>reset</name>
      <anchorfile>class_rsa_toolbox_1_1_log.html</anchorfile>
      <anchor>a1de8621bff09767dbcf4a08b4f13b590</anchor>
      <arglist>(QString directory, QString filename, QString appplicationName, QString applicationVersion)</arglist>
    </member>
    <member kind="function">
      <type>Log &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>class_rsa_toolbox_1_1_log.html</anchorfile>
      <anchor>a84e5e02749f37aa0f05ef64ea3b8bb93</anchor>
      <arglist>(T item)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::NameLabel</name>
    <filename>class_rsa_toolbox_1_1_name_label.html</filename>
    <member kind="function">
      <type></type>
      <name>NameLabel</name>
      <anchorfile>class_rsa_toolbox_1_1_name_label.html</anchorfile>
      <anchor>a32b9e57d90bb3f52ab2e72411fd80b8d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameLabel</name>
      <anchorfile>class_rsa_toolbox_1_1_name_label.html</anchorfile>
      <anchor>a05b2e59d5f1b335276613700c67ecfa8</anchor>
      <arglist>(QString name, QString label=&quot;&quot;)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>displayText</name>
      <anchorfile>class_rsa_toolbox_1_1_name_label.html</anchorfile>
      <anchor>a9944fb6e1c6c1323263e37bdba06c2b4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>name</name>
      <anchorfile>class_rsa_toolbox_1_1_name_label.html</anchorfile>
      <anchor>a2b0a198f837184bf6fff555cee3ce770</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>label</name>
      <anchorfile>class_rsa_toolbox_1_1_name_label.html</anchorfile>
      <anchor>a9acc60996c9e03257803daf0176fb1ff</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setName</name>
      <anchorfile>class_rsa_toolbox_1_1_name_label.html</anchorfile>
      <anchor>a6220fae15759fd0fa7d75e415df34e83</anchor>
      <arglist>(QString name)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setLabel</name>
      <anchorfile>class_rsa_toolbox_1_1_name_label.html</anchorfile>
      <anchor>adbee8ee5ce0807424c561759be441a6f</anchor>
      <arglist>(QString label)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator QString</name>
      <anchorfile>class_rsa_toolbox_1_1_name_label.html</anchorfile>
      <anchor>ab73a351240de6739ff051d7ea2b519a9</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_name_label.html</anchorfile>
      <anchor>ac68b0ea1c139eb137c1dc7d27c4f3fbb</anchor>
      <arglist>(const NameLabel &amp;other)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>separate</name>
      <anchorfile>class_rsa_toolbox_1_1_name_label.html</anchorfile>
      <anchor>aef396c61d0f357b8d0894cdb34722232</anchor>
      <arglist>(QVector&lt; NameLabel &gt; nameLabels, QStringList &amp;names, QStringList &amp;labels)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static QStringList</type>
      <name>names</name>
      <anchorfile>class_rsa_toolbox_1_1_name_label.html</anchorfile>
      <anchor>a48a44169904a3807691b7fc94061ebcf</anchor>
      <arglist>(QVector&lt; NameLabel &gt; nameLabels)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static QStringList</type>
      <name>labels</name>
      <anchorfile>class_rsa_toolbox_1_1_name_label.html</anchorfile>
      <anchor>ae856a3af0885b7dc756e944ef3ec8e50</anchor>
      <arglist>(QVector&lt; NameLabel &gt; nameLabels)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static QStringList</type>
      <name>displayText</name>
      <anchorfile>class_rsa_toolbox_1_1_name_label.html</anchorfile>
      <anchor>a1339ebc30774b6c011e421721f90482b</anchor>
      <arglist>(QVector&lt; NameLabel &gt; nameLabels)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static QVector&lt; NameLabel &gt;</type>
      <name>parse</name>
      <anchorfile>class_rsa_toolbox_1_1_name_label.html</anchorfile>
      <anchor>ab2cee817273c5ec8e97dc610fd3d33be</anchor>
      <arglist>(QString list, QString separator)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static QVector&lt; NameLabel &gt;</type>
      <name>parse</name>
      <anchorfile>class_rsa_toolbox_1_1_name_label.html</anchorfile>
      <anchor>aad58e501ac5920294765053ccea54d14</anchor>
      <arglist>(QString list, QString separator, QString ignore)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>class_rsa_toolbox_1_1_name_label.html</anchorfile>
      <anchor>ac81edb84e781d0af1ce64de2dc8e565e</anchor>
      <arglist>(const NameLabel &amp;right, const NameLabel &amp;left)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>class_rsa_toolbox_1_1_name_label.html</anchorfile>
      <anchor>adb4323fb7881a60c4ac712d5e3ac5c4f</anchor>
      <arglist>(const NameLabel &amp;right, const NameLabel &amp;left)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::NetworkData</name>
    <filename>class_rsa_toolbox_1_1_network_data.html</filename>
    <member kind="function">
      <type></type>
      <name>NetworkData</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>a52e989e1ee11765602685bf2b7cbb38e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NetworkData</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>a2e928d91064ec72b0f0e3f6c1b4e9af4</anchor>
      <arglist>(const NetworkData &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isSParameter</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>acd64e09a591153f70f022c88ac6d8e11</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isYParameter</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>a9360cf5c728954a11b1f2eb42efb2132</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isZParameter</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>a067ef92ffde57aed2f074b76b25f4de5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isHParameter</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>a25530aa955c1d0c46c4ebc1cfec6a9fd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isGParameter</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>a58f79a2c92c0df7905a139011a5301ad</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>NetworkParameter</type>
      <name>parameter</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>a20e8c472409a84c90c27d4684f9e2a4c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setParameter</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>a9add42f3f6bbe8cf30b017642a2ac624</anchor>
      <arglist>(NetworkParameter parameter)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>comment</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>a3c95db3c3fdd786ae1ba0c810000c43a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setComment</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>ab3a897eff60f58840c8d1b40292cf047</anchor>
      <arglist>(QString comment)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>timestamp</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>a71198a4f2505d4c3a4de5ad446f94eb3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>numberOfPorts</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>ae01c1b858e5255513f08de605f70e4ef</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>portComment</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>a564e97d4435907e526f223f96a42d8fc</anchor>
      <arglist>(uint port)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPortComment</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>a095fac6b4c1edd65b817a697587a2094</anchor>
      <arglist>(uint port, QString comment)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>referenceImpedance_Ohms</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>ac2eef00da8b65eff22fa4db6d630bd11</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setReferenceImpedance</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>ad0483d3936563c1dfa6166fd0cf852cc</anchor>
      <arglist>(double Ohms)</arglist>
    </member>
    <member kind="function">
      <type>Units</type>
      <name>xUnits</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>a8389cce4e499190179d070e95fe8e236</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>SiPrefix</type>
      <name>xPrefix</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>adee659c807b8ceba69ed7e727cadef42</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setXUnits</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>abe36b48d13d4d973c33ed0a59b32d802</anchor>
      <arglist>(Units units, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>points</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>acbdc0bd270e1acb2eee1f8c9a7f9a85d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>x</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>a72cb2736f6dcdb7ca9ce5eabf80b575e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix3D &amp;</type>
      <name>y</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>a1eaada33a0cfa9f5eca046d69e7e0e7b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>y_dB</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>a7e947c18985160f7416b2544ba05d9fe</anchor>
      <arglist>(uint outputPort, uint inputPort)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>y_magnitude</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>a90920758dfab708d7af9d907069bd157</anchor>
      <arglist>(uint outputPort, uint inputPort)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>y_phase_deg</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>a7bedcf12c80754a10b357ba182424562</anchor>
      <arglist>(uint outputPort, uint inputPort)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>y_phase_rad</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>af8f958d5984a277f455c00f4a22e498f</anchor>
      <arglist>(uint outputPort, uint inputPort)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>y_vswr</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>a6c68a1d9a9e36b3fbdd09e43105a9566</anchor>
      <arglist>(uint port)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>y_real</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>a5d87e4aac23b9624d2fed5146189356a</anchor>
      <arglist>(uint outputPort, uint inputPort)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>y_imaginary</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>a2857d32f3afd5a73535f5ca1676d5586</anchor>
      <arglist>(uint outputPort, uint inputPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setData</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>a1b9a5f48132418165cbd8c40fa443f20</anchor>
      <arglist>(QRowVector const &amp;x, ComplexMatrix3D const &amp;y)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>ab1b1fa63017bf3f4284656b972e820a1</anchor>
      <arglist>(const NetworkData &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>QDataStream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>a0d37c0948a9b5e2e1f05fcf89967c761</anchor>
      <arglist>(QDataStream &amp;stream)</arglist>
    </member>
    <member kind="function">
      <type>QDataStream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>class_rsa_toolbox_1_1_network_data.html</anchorfile>
      <anchor>a9d84e2945d93431f1376c4370561cbd0</anchor>
      <arglist>(QDataStream &amp;stream)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::NetworkTraceData</name>
    <filename>class_rsa_toolbox_1_1_network_trace_data.html</filename>
    <member kind="function">
      <type></type>
      <name>NetworkTraceData</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a8d33a428ee1de4a2885b5bfcfeb898eb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NetworkTraceData</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a3fad973fb72ff4b657445aa7d436f63d</anchor>
      <arglist>(const NetworkTraceData &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isSParameter</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>acd64e09a591153f70f022c88ac6d8e11</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isYParameter</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a9360cf5c728954a11b1f2eb42efb2132</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isZParameter</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a067ef92ffde57aed2f074b76b25f4de5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isHParameter</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a25530aa955c1d0c46c4ebc1cfec6a9fd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isGParameter</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a58f79a2c92c0df7905a139011a5301ad</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setParameter</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a9add42f3f6bbe8cf30b017642a2ac624</anchor>
      <arglist>(NetworkParameter parameter)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>comment</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a3c95db3c3fdd786ae1ba0c810000c43a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setComment</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>ab3a897eff60f58840c8d1b40292cf047</anchor>
      <arglist>(QString comment)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>timestamp</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a71198a4f2505d4c3a4de5ad446f94eb3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>outputPort</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a8a2a810c9ff6f32c02eb56f379fcef75</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setOutputPort</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>ab3e7a1a2da353c724dea2ddc71fecd2e</anchor>
      <arglist>(uint logicalPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>outputPort</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>ab4c696032924ae056ac23fe1a5687489</anchor>
      <arglist>(BalancedPort &amp;port)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setOutputPort</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>ae02b5ae29ba59125dd748adbc15293cc</anchor>
      <arglist>(BalancedPort port)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>outputPortComment</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>acf33ed569f3c07ce9e9c8ab3f83b7624</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setOutputPortComment</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a0097304e865774a040b340fc57bd9d00</anchor>
      <arglist>(QString comment)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>inputPort</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a094e4a04e3fb54dd11814d1818782827</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setInputPort</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a7355fa6e4381653e14fbae46411402e0</anchor>
      <arglist>(uint logicalPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>inputPort</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a256ecc46ad50fdf5fc6bff19eb1ca411</anchor>
      <arglist>(BalancedPort &amp;port)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setInputPort</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a56f24a4f7a838c3a83cdf01291ddccdd</anchor>
      <arglist>(BalancedPort port)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>inputPortComment</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a8bbea35fce63bd80cec48e4c1b690db6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setInputPortComment</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a004508ca9a491dc1731e0fddf687654f</anchor>
      <arglist>(QString comment)</arglist>
    </member>
    <member kind="function">
      <type>Units</type>
      <name>xUnits</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a8389cce4e499190179d070e95fe8e236</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>SiPrefix</type>
      <name>xPrefix</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>adee659c807b8ceba69ed7e727cadef42</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setXUnits</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>abe36b48d13d4d973c33ed0a59b32d802</anchor>
      <arglist>(Units units, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>points</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>acbdc0bd270e1acb2eee1f8c9a7f9a85d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>x</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a72cb2736f6dcdb7ca9ce5eabf80b575e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>y</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a2c6d8dd816feb9a25741bc869317d365</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>y_dB</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a46342214d6dea08920a5598a54498ae6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>y_magnitude</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a00b9d14a21e7f73cc418420c961db921</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>y_phase_deg</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a1029445de41699822d3a26f9b3728d38</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>y_phase_rad</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>aa2e177fe69c6184ffdd8b5718b7d026a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>y_vswr</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a060d038e5d1a58d01b117b583209d7d3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>y_real</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a55d05afa91bb87fa9b67ff4e528bb079</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>y_imaginary</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a320a2b31d61d9d662dcb8697195826c1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setData</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>a2169be2db19084ec5ec837a9e0ea136a</anchor>
      <arglist>(QRowVector const &amp;x, ComplexRowVector const &amp;y)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_network_trace_data.html</anchorfile>
      <anchor>aa7e50a1cae50dfd5feafc3c0ed00a76e</anchor>
      <arglist>(const NetworkTraceData &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::Rsc</name>
    <filename>class_rsa_toolbox_1_1_rsc.html</filename>
    <member kind="slot">
      <type>void</type>
      <name>EnableCorrection</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>a32b541b19cb3f614a39716408c6abdaa</anchor>
      <arglist>(bool isEnabled=true)</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>DisableCorrection</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>ad7d59a14cf618433b96e9d54f9b968e5</anchor>
      <arglist>(bool isDisabled=true)</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>SetUnitIndex</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>a811b808c21f34c8c3e86e3d8487885a2</anchor>
      <arglist>(uint index)</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>SetAttenuation</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>a035c88101795af6b66181163ed348679</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>SetUserCalibrationState</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>a6512a6ccaad4b28dbb3603c6b0078b84</anchor>
      <arglist>(RscCalibrationState state)</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>LoadUserCalibrationFile</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>a5ddb10856cdae9f7f6e51b4baf2054aa</anchor>
      <arglist>(QString filename)</arglist>
    </member>
    <member kind="signal">
      <type>void</type>
      <name>Print</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>ad31850e998eb495e68b827080280bded</anchor>
      <arglist>(QString formatted_text)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Rsc</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>abfadd8abef686f79c61f9390bbaefe46</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Rsc</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>afbbbc232d8d0db0c238a2ceaca171dc3</anchor>
      <arglist>(ConnectionType connection_type, QString address, uint timeout_ms, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~Rsc</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>ad508f97dd7bfc25e55964449ff0698ba</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>ConnectLog</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>a3eacd52cdda57615f4f697485641c1c8</anchor>
      <arglist>(Log &amp;log)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>DisconnectLog</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>aef11d5075fbd15c59f62aa5e61f3ba3e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>GetIdString</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>aeb31884dad38db6d2055ac78afd8a739</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>RscModel</type>
      <name>GetModel</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>a76919e9866cadf6d780c0f1496f6f5ad</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>GetSerialNumber</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>ae8f336ac286184151e80cc069d78a3c4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>GetFirmwareVersion</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>a017e6af5b01236c4e455d09a364294e9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isConnected</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>a772f8f0487e0d3804e9da7585e23a29a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isOperationComplete</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>acb2283a6cb20418383f3f512caf30550</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isError</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>af0c21ff963e9cdf07e3f0412f38de4e4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isCorrectionEnabled</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>aeedf29c86fcf70a77c868424be2069dd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isCorrectionDisabled</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>a86ac23c66979e541a1b063aad51f6fd9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isBaseUnit</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>a2b41ec391f85fa5a43924b8404228b9e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>ClearErrors</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>a9973f377b3ae387fc9c0ca2f127938ba</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; QStringList &gt;</type>
      <name>GetAvailableUnits</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>a6b92e6eb7a4e48ce7c631bbe92fcd303</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>GetUnitIndex</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>a9ff6095343efe46bb555aab8c8a8aeed</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>GetAttenuation_dB</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>a10d8e37f144f84eab670388ea8a71459</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>RscCalibrationState</type>
      <name>GetUserCalibrationState</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>ab0b2b75852c981f0508240748075aaa2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>GetMinimumFrequency_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>a63398b5425d20dc765340bba434866b9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>GetMaximumFrequency_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>af09115e81c275a8419c68b8f49c89397</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>GetMaximumPower_dBm</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>a036579d578d7ee0021c6fdfcfd19fee7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>GetMaximumAttenuation_dB</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>ae7318a20db7284abee0a07efc81a08b0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>GetStepSize_dB</name>
      <anchorfile>class_rsa_toolbox_1_1_rsc.html</anchorfile>
      <anchor>a20067873c59c1a63ffeca7ac73299f54</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::RsibBus</name>
    <filename>class_rsa_toolbox_1_1_rsib_bus.html</filename>
    <base>RsaToolbox::GenericBus</base>
    <member kind="slot">
      <type>bool</type>
      <name>lock</name>
      <anchorfile>class_rsa_toolbox_1_1_rsib_bus.html</anchorfile>
      <anchor>abde223cb8968835b7f8f060e505facc2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>bool</type>
      <name>unlock</name>
      <anchorfile>class_rsa_toolbox_1_1_rsib_bus.html</anchorfile>
      <anchor>ae399421ee39cae4df5ea44bd21e31254</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>bool</type>
      <name>local</name>
      <anchorfile>class_rsa_toolbox_1_1_rsib_bus.html</anchorfile>
      <anchor>ae4642a972205ef378bb3a1550a8418d8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>bool</type>
      <name>remote</name>
      <anchorfile>class_rsa_toolbox_1_1_rsib_bus.html</anchorfile>
      <anchor>a6f0890ff36c5a5fb58cdaca77e3f15f9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>printStatus</name>
      <anchorfile>class_rsa_toolbox_1_1_rsib_bus.html</anchorfile>
      <anchor>a30d7b394b3d6932f045f69a7980fa888</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RsibBus</name>
      <anchorfile>class_rsa_toolbox_1_1_rsib_bus.html</anchorfile>
      <anchor>a00496bd19d2d08358d65eb4a08c25004</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RsibBus</name>
      <anchorfile>class_rsa_toolbox_1_1_rsib_bus.html</anchorfile>
      <anchor>a0d573a040d981a0c3c95d20b96c6d2dd</anchor>
      <arglist>(ConnectionType connectionType, QString address, uint bufferSize_B=500, uint timeout_ms=1000, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~RsibBus</name>
      <anchorfile>class_rsa_toolbox_1_1_rsib_bus.html</anchorfile>
      <anchor>a7f9a1530ba625fd1de2d5c5da50f3663</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isOpen</name>
      <anchorfile>class_rsa_toolbox_1_1_rsib_bus.html</anchorfile>
      <anchor>a3c7351cec1380d07f9e4b3ec96b2b1ff</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setTimeout</name>
      <anchorfile>class_rsa_toolbox_1_1_rsib_bus.html</anchorfile>
      <anchor>a64f8674ed2fc1bf521b82b2c0523d310</anchor>
      <arglist>(uint time_ms)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>_read</name>
      <anchorfile>class_rsa_toolbox_1_1_rsib_bus.html</anchorfile>
      <anchor>ac91a11aa027b98dbb294a7450a41998b</anchor>
      <arglist>(char *buffer, uint bufferSize)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>_write</name>
      <anchorfile>class_rsa_toolbox_1_1_rsib_bus.html</anchorfile>
      <anchor>a2dbf98a161012f4de9bd4f5ac988bb68</anchor>
      <arglist>(QString scpiCommand)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>_binaryRead</name>
      <anchorfile>class_rsa_toolbox_1_1_rsib_bus.html</anchorfile>
      <anchor>af1ea84c6920ca23eadf907885511d3aa</anchor>
      <arglist>(char *buffer, uint bufferSize, uint &amp;bytesRead)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>_binaryWrite</name>
      <anchorfile>class_rsa_toolbox_1_1_rsib_bus.html</anchorfile>
      <anchor>a59cb83b7cd82a8afe1dbdedf26bfdd89</anchor>
      <arglist>(QByteArray scpiCommand)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::SnpStreamReader</name>
    <filename>class_rsa_toolbox_1_1_snp_stream_reader.html</filename>
    <member kind="function">
      <type></type>
      <name>SnpStreamReader</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_reader.html</anchorfile>
      <anchor>a574e28260ad4f43b62ea759151d59c30</anchor>
      <arglist>(QString filePathName)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setFilename</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_reader.html</anchorfile>
      <anchor>ac1427daa2c0b008e34996baf542e3ef4</anchor>
      <arglist>(QString filePathName)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isOpen</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_reader.html</anchorfile>
      <anchor>a3a9ba7594ee74425dd345ecc263a5564</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>open</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_reader.html</anchorfile>
      <anchor>adb20eae91802d6ad6366cdee0220c280</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isClosed</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_reader.html</anchorfile>
      <anchor>aa4391a4781bebbb4e1343951b6616cd3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>close</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_reader.html</anchorfile>
      <anchor>a5ae591df94fc66ccb85cbb6565368bca</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>NetworkParameter</type>
      <name>parameter</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_reader.html</anchorfile>
      <anchor>a20e8c472409a84c90c27d4684f9e2a4c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>impedance_Ohms</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_reader.html</anchorfile>
      <anchor>a51b5fa4646fdb97add58d53558c2fed3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>ports</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_reader.html</anchorfile>
      <anchor>a2bf03b7bfda0414cb985e35c05744ce0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotData</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_reader.html</anchorfile>
      <anchor>a140f1379a7ed4eeb704a754b7c5a0b95</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isData</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_reader.html</anchorfile>
      <anchor>ab67440fd01b8a57c2cec231bd388dfa9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>point</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_reader.html</anchorfile>
      <anchor>a27e6af02994cf850eb31e8260e207521</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>seekForward</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_reader.html</anchorfile>
      <anchor>a9838e9d928470e85eca175bc9933a9da</anchor>
      <arglist>(double frequency, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>peek</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_reader.html</anchorfile>
      <anchor>aa679d9fc0a29f0581f30b99e5f5751f7</anchor>
      <arglist>(double &amp;frequency_Hz, ComplexMatrix2D &amp;data)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>next</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_reader.html</anchorfile>
      <anchor>a80870c233d0237e3588a2d6f8d176916</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>frequency_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_reader.html</anchorfile>
      <anchor>a91acfcdb00405d0e48878c2bc69caa14</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix2D</type>
      <name>data</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_reader.html</anchorfile>
      <anchor>afb65dc3f47c67e570e60d444cf860795</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>ComplexDouble</type>
      <name>data</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_reader.html</anchorfile>
      <anchor>a3d4e0ae4c42f9537ad990f1b1a171786</anchor>
      <arglist>(uint outputPort, uint inputPort)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::SnpStreamWriter</name>
    <filename>class_rsa_toolbox_1_1_snp_stream_writer.html</filename>
    <member kind="function">
      <type></type>
      <name>SnpStreamWriter</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_writer.html</anchorfile>
      <anchor>a409581e2827a9447f147cba95b97115f</anchor>
      <arglist>(QString filePathName)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>SnpStreamWriter</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_writer.html</anchorfile>
      <anchor>a23b1254e629cff60dd84d63954671b29</anchor>
      <arglist>(QString filePathName, uint ports)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>setFileName</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_writer.html</anchorfile>
      <anchor>a71ee1bcf2137974defe20459651c5f2d</anchor>
      <arglist>(QString filePathName)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>setFileName</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_writer.html</anchorfile>
      <anchor>ad0ee92e49816a028eba201296acc7cfa</anchor>
      <arglist>(QString filePathName, uint ports)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>rename</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_writer.html</anchorfile>
      <anchor>aa61cd4c0e8caca201bc2ace0e258ef7a</anchor>
      <arglist>(QString filePathName)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isValidFilename</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_writer.html</anchorfile>
      <anchor>a99f4bcd50de26c60cf30832417f1bfbe</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isOpen</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_writer.html</anchorfile>
      <anchor>a3a9ba7594ee74425dd345ecc263a5564</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isClosed</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_writer.html</anchorfile>
      <anchor>aa4391a4781bebbb4e1343951b6616cd3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>open</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_writer.html</anchorfile>
      <anchor>adb20eae91802d6ad6366cdee0220c280</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>close</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_writer.html</anchorfile>
      <anchor>a5ae591df94fc66ccb85cbb6565368bca</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>writeCommentLine</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_writer.html</anchorfile>
      <anchor>adef3f12588fcbfe7ca6b21640ab67fd0</anchor>
      <arglist>(QString comment)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeOptions</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_writer.html</anchorfile>
      <anchor>a3a815830810b75d47fd8a28a754cb78a</anchor>
      <arglist>(NetworkParameter parameter=S_PARAMETER, SiPrefix frequencyPrefix=NO_PREFIX, ComplexFormat format=REAL_IMAGINARY_COMPLEX, double impedance_Ohms=50)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writePoint</name>
      <anchorfile>class_rsa_toolbox_1_1_snp_stream_writer.html</anchorfile>
      <anchor>a740fb15b501d1bfd2ac8975e75438a44</anchor>
      <arglist>(double const &amp;frequency, ComplexMatrix2D const &amp;matrix)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::Touchstone</name>
    <filename>class_rsa_toolbox_1_1_touchstone.html</filename>
    <member kind="function" static="yes">
      <type>static uint</type>
      <name>ports</name>
      <anchorfile>class_rsa_toolbox_1_1_touchstone.html</anchorfile>
      <anchor>a9151d815ca67c804e2684487963634f1</anchor>
      <arglist>(QString fileName)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>Read</name>
      <anchorfile>class_rsa_toolbox_1_1_touchstone.html</anchorfile>
      <anchor>ae986ab885883976bb96f1323c4acb019</anchor>
      <arglist>(NetworkData &amp;network, QTextStream &amp;touchstone_in, int ports)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>Read</name>
      <anchorfile>class_rsa_toolbox_1_1_touchstone.html</anchorfile>
      <anchor>a99e50d32edc83325828f93466a731e32</anchor>
      <arglist>(NetworkData &amp;network, QString filename)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>Write</name>
      <anchorfile>class_rsa_toolbox_1_1_touchstone.html</anchorfile>
      <anchor>a6143cc2562bf17edc99f4f5a3be8d4d4</anchor>
      <arglist>(NetworkData &amp;network, QTextStream &amp;touchstone_out)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>Write</name>
      <anchorfile>class_rsa_toolbox_1_1_touchstone.html</anchorfile>
      <anchor>a75ea7e0ce229b6317a1970a0de3e83ef</anchor>
      <arglist>(NetworkData &amp;network, QString filename)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VisaBus</name>
    <filename>class_rsa_toolbox_1_1_visa_bus.html</filename>
    <base>RsaToolbox::GenericBus</base>
    <member kind="slot">
      <type>bool</type>
      <name>lock</name>
      <anchorfile>class_rsa_toolbox_1_1_visa_bus.html</anchorfile>
      <anchor>abde223cb8968835b7f8f060e505facc2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>bool</type>
      <name>unlock</name>
      <anchorfile>class_rsa_toolbox_1_1_visa_bus.html</anchorfile>
      <anchor>ae399421ee39cae4df5ea44bd21e31254</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>bool</type>
      <name>local</name>
      <anchorfile>class_rsa_toolbox_1_1_visa_bus.html</anchorfile>
      <anchor>ae4642a972205ef378bb3a1550a8418d8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>bool</type>
      <name>remote</name>
      <anchorfile>class_rsa_toolbox_1_1_visa_bus.html</anchorfile>
      <anchor>a6f0890ff36c5a5fb58cdaca77e3f15f9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>printStatus</name>
      <anchorfile>class_rsa_toolbox_1_1_visa_bus.html</anchorfile>
      <anchor>a30d7b394b3d6932f045f69a7980fa888</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VisaBus</name>
      <anchorfile>class_rsa_toolbox_1_1_visa_bus.html</anchorfile>
      <anchor>ae8408f4c9e12945eb7e3c257d9f1c3af</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VisaBus</name>
      <anchorfile>class_rsa_toolbox_1_1_visa_bus.html</anchorfile>
      <anchor>ad5deae57f1e8ab91bf43fe9fc8705f80</anchor>
      <arglist>(ConnectionType connectionType, QString address, uint bufferSize_B=500, uint timeout_ms=1000, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~VisaBus</name>
      <anchorfile>class_rsa_toolbox_1_1_visa_bus.html</anchorfile>
      <anchor>af118a288752ad112061fac28c1d029cd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isOpen</name>
      <anchorfile>class_rsa_toolbox_1_1_visa_bus.html</anchorfile>
      <anchor>a3c7351cec1380d07f9e4b3ec96b2b1ff</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setTimeout</name>
      <anchorfile>class_rsa_toolbox_1_1_visa_bus.html</anchorfile>
      <anchor>a64f8674ed2fc1bf521b82b2c0523d310</anchor>
      <arglist>(uint time_ms)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>isVisaPresent</name>
      <anchorfile>class_rsa_toolbox_1_1_visa_bus.html</anchorfile>
      <anchor>aa1016fa7162d3893d90f4e6d03ee622f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>_read</name>
      <anchorfile>class_rsa_toolbox_1_1_visa_bus.html</anchorfile>
      <anchor>ac91a11aa027b98dbb294a7450a41998b</anchor>
      <arglist>(char *buffer, uint bufferSize)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>_write</name>
      <anchorfile>class_rsa_toolbox_1_1_visa_bus.html</anchorfile>
      <anchor>a2dbf98a161012f4de9bd4f5ac988bb68</anchor>
      <arglist>(QString scpiCommand)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>_binaryRead</name>
      <anchorfile>class_rsa_toolbox_1_1_visa_bus.html</anchorfile>
      <anchor>af1ea84c6920ca23eadf907885511d3aa</anchor>
      <arglist>(char *buffer, uint bufferSize, uint &amp;bytesRead)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>_binaryWrite</name>
      <anchorfile>class_rsa_toolbox_1_1_visa_bus.html</anchorfile>
      <anchor>a59cb83b7cd82a8afe1dbdedf26bfdd89</anchor>
      <arglist>(QByteArray scpiCommand)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::Vna</name>
    <filename>class_rsa_toolbox_1_1_vna.html</filename>
    <base>RsaToolbox::GenericInstrument</base>
    <member kind="function">
      <type></type>
      <name>Vna</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>ae35ba6409591fefaa4bd01724d592a33</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Vna</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>abf2c50ec714bcf258b2cc7ca680de035</anchor>
      <arglist>(GenericBus *bus, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Vna</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a8bb04d1d8f4b1cfe67397d3c5cf6767c</anchor>
      <arglist>(ConnectionType type, QString address, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>printInfo</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a2dbaf5580b5305d54cff6848ae7deb30</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>printInfo</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>ada409285acc32db14ccc3e8e99beb740</anchor>
      <arglist>(QTextStream &amp;stream)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>readVector</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a0650976dcff919626ebaade4346800c8</anchor>
      <arglist>(uint bufferSize_B=5000, uint timeout_ms=1000)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>readComplexVector</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>abb69dcb6930ac6a0f53efc9d5776e57e</anchor>
      <arglist>(uint bufferSize_B=5000, uint timeout_ms=1000)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>queryVector</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a63b4ac253ad026c8f013721c56f96e03</anchor>
      <arglist>(QString scpi, uint bufferSize_B=5000, uint timeout_ms=1000)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>queryComplexVector</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a28798e7559461b9761caac24d1440897</anchor>
      <arglist>(QString scpi, uint bufferSize_B=5000, uint timeout_ms=1000)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isError</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>af0c21ff963e9cdf07e3f0412f38de4e4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isError</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>ac64321b09444ed39f4b122e26fd782c9</anchor>
      <arglist>(QString &amp;errorString)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isError</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a49cda2ce4622889f356862343214ebbe</anchor>
      <arglist>(QStringList &amp;errors)</arglist>
    </member>
    <member kind="function">
      <type>VnaProperties &amp;</type>
      <name>properties</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a4515e7a85cbf9e5c92cc01b11c831234</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaProperties *</type>
      <name>takeProperties</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>aaa98bf8483c7bf0854b9b51cf39264c9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaSettings &amp;</type>
      <name>settings</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>affcacca0956ef82c5b28506a036498e8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaSettings *</type>
      <name>takeSettings</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a503614ce24abf00d2d2640c66b3f1c3f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaFileSystem &amp;</type>
      <name>fileSystem</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>addfb84d6ffe1b6c7998540a862199f85</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaFileSystem *</type>
      <name>takeFileSystem</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>ad3fa75296b71d2e67001526f98ae3e44</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; Connector &gt;</type>
      <name>connectorTypes</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>ad67ace0c386c3deb2e841fdad13f448e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isConnectorType</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>ace47065a2e5e9845e4e86ff76a999b16</anchor>
      <arglist>(Connector type)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isConnectorType</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a8d35e35d7d6b23d93a53228f5d7ca011</anchor>
      <arglist>(QString userDefinedType)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isCalKit</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>ae99b92b85ffd250a767e8f083f21415a</anchor>
      <arglist>(NameLabel nameLabel)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isCalKit</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>aa2d101ac75c27061aa0c03aea882bd22</anchor>
      <arglist>(QString name, QString label)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotCalKit</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a8cb2b1b450b71c8ca8365c3a75fa42b7</anchor>
      <arglist>(NameLabel nameLabel)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotCalKit</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a8fee8c7369e24bf755452a6f76502453</anchor>
      <arglist>(QString name, QString label)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; NameLabel &gt;</type>
      <name>calKits</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a9a3a033dfb8fe01d79d2b5b36e6e385a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; NameLabel &gt;</type>
      <name>calKits</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a893bafc910d0eccdbb8ff3e8bc81c837</anchor>
      <arglist>(Connector type)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; NameLabel &gt;</type>
      <name>calKits</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>aabb899750fb3c7c6f9f81b4b3901376b</anchor>
      <arglist>(ConnectorType type)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; NameLabel &gt;</type>
      <name>calKits</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>ac931fd9d6c89be8445746ddd63a76490</anchor>
      <arglist>(QString userDefinedConnectorType)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>importCalKit</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>ab1cb02a44b48bed030b04cfe9bbfbcf2</anchor>
      <arglist>(QString pathName)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>exportCalKit</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a1e8e199ac870aa517ce5cf4b44ba3452</anchor>
      <arglist>(NameLabel calkit, QString pathName)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteCalKit</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a7e12c9a6636124f2beb6bca04c28054f</anchor>
      <arglist>(NameLabel calkit)</arglist>
    </member>
    <member kind="function">
      <type>VnaCalKit &amp;</type>
      <name>calKit</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a9a1ae54c95fdba0b0dbfd4ac450c10c4</anchor>
      <arglist>(NameLabel nameLabel)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; uint &gt;</type>
      <name>calibratedChannels</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a522defb3438d3aaac8dd6fd71de04a52</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaCalibrate &amp;</type>
      <name>calibrate</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a85ef0d9299e04b6ad4c9448c444fc206</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaCalibrate *</type>
      <name>takeCalibrate</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a17813337ac4d01f73de6d925918c31a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QStringList</type>
      <name>calGroups</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a9bb813257723c4e0c670b5fe0759a1fb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isChannel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>adaa3910833eb41cffd1303618d794404</anchor>
      <arglist>(uint index)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isChannel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>af74e3ba98044d169130895b8797f8a45</anchor>
      <arglist>(QString name)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotChannel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a2b3c37c94062a6db9a915978a97132e1</anchor>
      <arglist>(uint index)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotChannel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a4c8df67f5cc8b4c0218271ce73045387</anchor>
      <arglist>(QString name)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>numberOfChannels</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>ab7e709afe715ea12d3fe089469458e39</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; uint &gt;</type>
      <name>channels</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>afea6252754a9fbd157f2d927ad88470b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>channelId</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a4f7d3dfa58e5fa355124509e7cafdfd1</anchor>
      <arglist>(QString name)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>createChannel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a22d2792c50b5919d1ed4939a707f42a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>createChannel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a5394b3e15ed64066cc188864b3cf9eaf</anchor>
      <arglist>(uint index)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteChannel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>acef380ecbb7f6460a3adb43d9b0c30aa</anchor>
      <arglist>(uint index)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteChannel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>aa02f17a1b8203e6e891d21273238496d</anchor>
      <arglist>(QString name)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteChannels</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a88d53538d5c055a4dd79875bb1773038</anchor>
      <arglist>(QVector&lt; uint &gt; indices)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteChannels</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a38c22ec37ff46bb05f636d144e05e6c4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaChannel &amp;</type>
      <name>channel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a6a49928953474b5d3d8eda5d2438907b</anchor>
      <arglist>(uint index=1)</arglist>
    </member>
    <member kind="function">
      <type>VnaChannel *</type>
      <name>takeChannel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>af32fc349faf160b87ad7b73d8f6690c1</anchor>
      <arglist>(uint index=1)</arglist>
    </member>
    <member kind="function">
      <type>VnaChannel *</type>
      <name>takeChannels</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>af5f3b35835024ad6a91b9252a58ad35c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isTrace</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>ac47677937a1b2e4807cca77c9bec6944</anchor>
      <arglist>(QString name)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>numberOfTraces</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>aa589497adb0d34965c0139be83f421ae</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QStringList</type>
      <name>traces</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a43cb9ed8da7e6710f50b5402792ac7e6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>createTrace</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>ac0795e14d09aa2d96eafc9e7d5cfddc5</anchor>
      <arglist>(QString name, uint channel)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteTrace</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>aec0a8a21739d27317e000f74ccb6edee</anchor>
      <arglist>(QString name)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteTraces</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>abf77ba9afb3df0556934292b78499734</anchor>
      <arglist>(QStringList traces)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteTraces</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>ab034ce3db42f3c2f7ac4ab94d3c3e1f8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaTrace &amp;</type>
      <name>trace</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>abfb62d021035eba2e741fe981d43c6da</anchor>
      <arglist>(QString name=&quot;Trc1&quot;)</arglist>
    </member>
    <member kind="function">
      <type>VnaTrace *</type>
      <name>takeTrace</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a392ab2b3b4d85056ddf59f7930f436a6</anchor>
      <arglist>(QString name=&quot;Trc1&quot;)</arglist>
    </member>
    <member kind="function">
      <type>VnaTrace *</type>
      <name>takeTraces</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a2d09df214f10ec2f92c48a6b7e3cee7a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isDiagram</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a03812f34d00ae2ac3c9cc1d0f58d5c93</anchor>
      <arglist>(uint index)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotDiagram</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a896c347c0be367bf7f2f72ac3c98b00d</anchor>
      <arglist>(uint index)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>numberOfDiagrams</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>afff3d4de60b4d48bc08e4f14a70bb282</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; uint &gt;</type>
      <name>diagrams</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>aa49393813f1cf620661930fc4ad70d3f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>createDiagram</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>aeff3524f91f7fbbd3265be80f0181e82</anchor>
      <arglist>(uint index)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>createDiagram</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a018e319f2e867c01458f1c1e9e6e23c8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteDiagram</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a74e7681f101d28822de37965ddfc438e</anchor>
      <arglist>(uint index)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteDiagrams</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a21f7508403b4170b3b1ce3e903bbd6a5</anchor>
      <arglist>(QVector&lt; uint &gt; diagrams)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteDiagrams</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a0d701a4b9ec44f64fa212aaa3fa13704</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>autoscaleDiagrams</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a2321ed51fd6157f9ae56dfc9da3df179</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaDiagram &amp;</type>
      <name>diagram</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a82d973ff6e159f183c0966c79f59365a</anchor>
      <arglist>(uint index=1)</arglist>
    </member>
    <member kind="function">
      <type>VnaDiagram *</type>
      <name>takeDiagram</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a58e48306b854ff20311bf381963bd3ce</anchor>
      <arglist>(uint index=1)</arglist>
    </member>
    <member kind="function">
      <type>VnaDiagram *</type>
      <name>takeDiagrams</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>aaab02a9c6572fa996ffe8391c316634e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>startSweeps</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>abc1ceb9a9678e4de6f0a713d947f416d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>testPorts</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a7d3bd486c8f2cb4e353868ec707b145b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isSwitchMatrix</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>adf847af4c791c3ed290ce1e0cc991bd7</anchor>
      <arglist>(uint index=1)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>numberOfSwitchMatrices</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a7d0d7026ee6bef687aacf0b725eaab85</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; uint &gt;</type>
      <name>switchMatrices</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>af35c2a5f614190d3c4ccdfe232b58f96</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>addSwitchMatrix</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>ac7326c667d2c27dac917ec55ac794297</anchor>
      <arglist>(uint index)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>addSwitchMatrix</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a076766d06e234da4574737c670235c55</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteSwitchMatrix</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>afe23b168d640debc37d36c410db63521</anchor>
      <arglist>(uint index)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteSwitchMatrices</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a47a02aba98d882c20f7d7c67f7fb16ac</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaSwitchMatrix &amp;</type>
      <name>switchMatrix</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a4fc198802de2aa7e9f6be80185cb1369</anchor>
      <arglist>(uint index=1)</arglist>
    </member>
    <member kind="function">
      <type>VnaSwitchMatrix *</type>
      <name>takeSwitchMatrix</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a5ed3ffbc6016a6f6ed9cd25daecaa065</anchor>
      <arglist>(uint index=1)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>isCalUnit</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>abe18a3e9886c78813893747e271b4e5a</anchor>
      <arglist>(QString id)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>numberOfCalUnits</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>aca2bc4db34f6af98228dfcd540c77a6c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QStringList</type>
      <name>calUnits</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>afe29686e38a9067c6064f1facba11de0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaCalUnit &amp;</type>
      <name>calUnit</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>ad98b94d258597f304e09b85f2fd97684</anchor>
      <arglist>(QString id)</arglist>
    </member>
    <member kind="function">
      <type>VnaCalUnit *</type>
      <name>takeCalUnit</name>
      <anchorfile>class_rsa_toolbox_1_1_vna.html</anchorfile>
      <anchor>a64df6113e20ed16eb1aa386d47582f5f</anchor>
      <arglist>(QString id)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaAveraging</name>
    <filename>class_rsa_toolbox_1_1_vna_averaging.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaAveraging</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_averaging.html</anchorfile>
      <anchor>a6db262c7f2503b3eb862c3deec35e28b</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaAveraging</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_averaging.html</anchorfile>
      <anchor>a60649eb55a5bc1c509fde15b6971c5d6</anchor>
      <arglist>(const VnaAveraging &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaAveraging</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_averaging.html</anchorfile>
      <anchor>a65c93c7c864512bf9200adc04d29dfa4</anchor>
      <arglist>(Vna *vna, VnaChannel *channel, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaAveraging</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_averaging.html</anchorfile>
      <anchor>a009ca368535a111ffdab78d2ef919434</anchor>
      <arglist>(Vna *vna, uint channelIndex, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_averaging.html</anchorfile>
      <anchor>a3909f77aa50b8f46ccadc196178a07a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_averaging.html</anchorfile>
      <anchor>a45cb35cce9c006e0f1428934f6d828cb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>on</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_averaging.html</anchorfile>
      <anchor>af5ab223c4aa62b4fc1bcc3a166bc2517</anchor>
      <arglist>(bool isOn=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>off</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_averaging.html</anchorfile>
      <anchor>a785abb1dda82d2aa86dca3b47ad8c5db</anchor>
      <arglist>(bool isOff=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>reset</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_averaging.html</anchorfile>
      <anchor>ad20897c5c8bd47f5d4005989bead0e55</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setNumber</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_averaging.html</anchorfile>
      <anchor>a7164308cc2798166e91dd4399a711e15</anchor>
      <arglist>(uint numberOfAverages)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>number</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_averaging.html</anchorfile>
      <anchor>afec7ebf45f016b1be11f3ac8e60745e4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_averaging.html</anchorfile>
      <anchor>aead155c4a862d892e0f0267285722ea6</anchor>
      <arglist>(VnaAveraging const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaCalibrate</name>
    <filename>class_rsa_toolbox_1_1_vna_calibrate.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaCalibrate</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_calibrate.html</anchorfile>
      <anchor>ac4f801dd2cc69d836f4181191c75d101</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaCalibrate</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_calibrate.html</anchorfile>
      <anchor>ac1852d0217a75c08f04d8f48cec24b11</anchor>
      <arglist>(VnaCalibrate &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaCalibrate</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_calibrate.html</anchorfile>
      <anchor>a08c3db9cc7b95b3312ea64c763dd40fb</anchor>
      <arglist>(Vna *vna, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaCalibrate</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_calibrate.html</anchorfile>
      <anchor>a870813b3182e7e5b918e216f2ff67554</anchor>
      <arglist>(Vna *vna, VnaChannel *channel, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaCalibrate</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_calibrate.html</anchorfile>
      <anchor>a17916056a0cfd8e7964008497a9fa4be</anchor>
      <arglist>(Vna *vna, uint channelIndex, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isRawDataKept</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_calibrate.html</anchorfile>
      <anchor>a1a229251cac896f1f4cd027588313012</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setConnector</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_calibrate.html</anchorfile>
      <anchor>a5be19415118f23c0d16084a60b90d33a</anchor>
      <arglist>(uint port, Connector connector)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setConnectors</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_calibrate.html</anchorfile>
      <anchor>ab52950f793d3a45b291191bf88ed317f</anchor>
      <arglist>(Connector connector)</arglist>
    </member>
    <member kind="function">
      <type>Connector</type>
      <name>connector</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_calibrate.html</anchorfile>
      <anchor>a4e8c2593d3bd095e75aec52c0c2dc7f9</anchor>
      <arglist>(uint port)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; Connector &gt;</type>
      <name>connectors</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_calibrate.html</anchorfile>
      <anchor>aa5a3dfdd57c9eba8eb08677f32c6f209</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>selectKit</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_calibrate.html</anchorfile>
      <anchor>ac1af0bae2ec05e295b972ab1122a4bad</anchor>
      <arglist>(NameLabel nameLabel)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>selectKit</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_calibrate.html</anchorfile>
      <anchor>a657fb038ee7640b6dfcddd5ca0856a7c</anchor>
      <arglist>(QString name, QString label=&quot;&quot;)</arglist>
    </member>
    <member kind="function">
      <type>NameLabel</type>
      <name>selectedKit</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_calibrate.html</anchorfile>
      <anchor>ad5116f2910b37ef1ed4bd30bae7449c8</anchor>
      <arglist>(Connector type)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>start</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_calibrate.html</anchorfile>
      <anchor>ab2ef3091f248d9bf4f27c770a0a29720</anchor>
      <arglist>(QString calibrationName, VnaCalType type, QVector&lt; uint &gt; ports)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>keepRawData</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_calibrate.html</anchorfile>
      <anchor>a8b05b89e74abc4abaadda024b6a3cf29</anchor>
      <arglist>(bool isKept=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>measureOpen</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_calibrate.html</anchorfile>
      <anchor>ac0a73da8f1d82b6aa967b9df74311989</anchor>
      <arglist>(uint port)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>measureShort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_calibrate.html</anchorfile>
      <anchor>afa03740e956b5361e8a0ad2018be1453</anchor>
      <arglist>(uint port)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>measureMatch</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_calibrate.html</anchorfile>
      <anchor>a085db48ef2ef7caf3134e20ea706ab4e</anchor>
      <arglist>(uint port)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>measureThru</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_calibrate.html</anchorfile>
      <anchor>abf9b48f61497d2f69c74ed7ec0aea719</anchor>
      <arglist>(uint port1, uint port2)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>apply</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_calibrate.html</anchorfile>
      <anchor>a95067243b72a23863ec07c821797455c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_calibrate.html</anchorfile>
      <anchor>ab9cb6d73b09f64e08e5db0600c4a4379</anchor>
      <arglist>(VnaCalibrate const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaCalKit</name>
    <filename>class_rsa_toolbox_1_1_vna_cal_kit.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaCalKit</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_kit.html</anchorfile>
      <anchor>a085130bab631ddee533c4352a859e3cf</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaCalKit</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_kit.html</anchorfile>
      <anchor>a9286f895dd1af893772bc5b94e856be7</anchor>
      <arglist>(const VnaCalKit &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaCalKit</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_kit.html</anchorfile>
      <anchor>a49dddc1f66c5af6ce852b157a785c1fd</anchor>
      <arglist>(Vna *vna, NameLabel nameLabel, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isConnectorType</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_kit.html</anchorfile>
      <anchor>ace47065a2e5e9845e4e86ff76a999b16</anchor>
      <arglist>(Connector type)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>has</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_kit.html</anchorfile>
      <anchor>ac881444c729b3dcbb0d7795b339ba3da</anchor>
      <arglist>(VnaCalStandard standard)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>has</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_kit.html</anchorfile>
      <anchor>a3ea08458b2fa30bb92804273b6892993</anchor>
      <arglist>(VnaStandardType type, ConnectorGender gender)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>has</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_kit.html</anchorfile>
      <anchor>a1144a2cb8651dbef4929da7110debbee</anchor>
      <arglist>(VnaStandardType type, uint port)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>has</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_kit.html</anchorfile>
      <anchor>afdcc6ea9e6eb647d3d778ddce96578a7</anchor>
      <arglist>(VnaStandardType type, ConnectorGender gender1, ConnectorGender gender2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>has</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_kit.html</anchorfile>
      <anchor>ac6b3cddf20e99a2e3aac18cadda8bfba</anchor>
      <arglist>(VnaStandardType type, uint port1, uint port2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>hasOpen</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_kit.html</anchorfile>
      <anchor>aa77229e8913e336b59a17a97f5342147</anchor>
      <arglist>(uint port)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>hasMaleOpen</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_kit.html</anchorfile>
      <anchor>afad02038620eb367cb51b1b77a33563b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>hasFemaleOpen</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_kit.html</anchorfile>
      <anchor>a90d4ebe10f18270b188eef8ea7d4018d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>hasShort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_kit.html</anchorfile>
      <anchor>a755dbadb8d2d1a431ebcc629e27a74c5</anchor>
      <arglist>(uint port)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>hasMaleShort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_kit.html</anchorfile>
      <anchor>aa6718c0bf1511a25cd323f711607a382</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>hasFemaleShort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_kit.html</anchorfile>
      <anchor>aff33e969409413472a5361186c142cd8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>hasMatch</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_kit.html</anchorfile>
      <anchor>ad7ec772a15f1d1190108c354ebdf794e</anchor>
      <arglist>(uint port)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>hasMaleMatch</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_kit.html</anchorfile>
      <anchor>a0bd352fadbd3842d921a22c99257c7ea</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>hasFemaleMatch</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_kit.html</anchorfile>
      <anchor>a173be47ae50acb3930206bf83550fd1e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>hasThru</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_kit.html</anchorfile>
      <anchor>a328dea68cba6fd0a539ff9c2ef6366c3</anchor>
      <arglist>(ConnectorGender gender1, ConnectorGender gender2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>hasThru</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_kit.html</anchorfile>
      <anchor>af185868fb8e074e1a1a310bd2850d020</anchor>
      <arglist>(uint port1, uint port2)</arglist>
    </member>
    <member kind="function">
      <type>Connector</type>
      <name>connectorType</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_kit.html</anchorfile>
      <anchor>a767579d3bacfc6f3e1b799cee4c6eb24</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; VnaCalStandard &gt;</type>
      <name>standards</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_kit.html</anchorfile>
      <anchor>a2ab5f06e4f221fb25ec30cd045805aa9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>addStandard</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_kit.html</anchorfile>
      <anchor>a955867302e471115559d91a7844d9092</anchor>
      <arglist>(VnaCalStandard standard)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_kit.html</anchorfile>
      <anchor>aaa5b8dc14505cd041b95628ba6d0ebf3</anchor>
      <arglist>(VnaCalKit const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaCalStandard</name>
    <filename>class_rsa_toolbox_1_1_vna_cal_standard.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaCalStandard</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a4efb480823e6644deb8001125624a9f2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaCalStandard</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a1c47fb50d92dce5ac18e40b7e4b5be93</anchor>
      <arglist>(VnaStandardType type, Connector connector)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaCalStandard</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a289e1807f97b458c41cbb661253d6424</anchor>
      <arglist>(VnaStandardType type, uint port)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaCalStandard</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>af457ff43ebf9afd6304b5b453aea4ec4</anchor>
      <arglist>(VnaStandardType type, Connector connector1, Connector connector2)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaCalStandard</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>ab05de67f9794479ffc3f44a63f38292b</anchor>
      <arglist>(VnaStandardType type, uint port1, uint port2)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>displayText</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a9944fb6e1c6c1323263e37bdba06c2b4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>displayType</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>aec201798cb33fcb3c7dffec7259e0a94</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isType</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a15131169b48ed2c3f915bb3480102135</anchor>
      <arglist>(VnaStandardType type) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotType</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>adb5919561105d9f52aae85f5835df3ff</anchor>
      <arglist>(VnaStandardType type) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isGender</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a6a72a4731f22fc54b667979d05a05b5a</anchor>
      <arglist>(ConnectorGender gender) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isGender</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a7b59485bf91281f29020b054c50dbd7d</anchor>
      <arglist>(ConnectorGender gender1, ConnectorGender gender2) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isMale</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>aebd8639c0076439cdc71eeac6c84c02f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isFemale</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>ac732e2378747c65b5ba737fe9c2c74e2</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isPortSpecific</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a9bb705e38f8c5740127237671e7c285d</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isPortSpecific</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a249af04b9a301c4eb5232ca00446d399</anchor>
      <arglist>(uint port) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isPortSpecific</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a063250466bc1ea70a2d4ce2f333f0580</anchor>
      <arglist>(uint port1, uint port2) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotPortSpecific</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a1712205fd44398910d0d7fb1c7f3a2e2</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isSinglePort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a42d28e6c44887dd9d8c11621b6ebccd8</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isTwoPort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>adcbf6ecdaf720f6f31b23be279a42685</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isSameStandardAs</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a9dc220ec1fb730d469e0e6735ed420b4</anchor>
      <arglist>(VnaCalStandard other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isOpen</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a3c7351cec1380d07f9e4b3ec96b2b1ff</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isOpen</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>ab199234a6baadf84c9846036b2e6cdac</anchor>
      <arglist>(uint port) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isMaleOpen</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a8825097e5839b7a5191c65044f3908d0</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isFemaleOpen</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a8c47d0bf0a8cfad7888deb7c8333cddd</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isShort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a7fdede916973f43849f720dff3fd81fe</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isShort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a76f3a560f7f7528291a9bf68393f3f7e</anchor>
      <arglist>(uint port) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isMaleShort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>acdabfad94b77629336e45d289a62a34d</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isFemaleShort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>aa51d7b758f4e1cbf378a0c68354de221</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isMatch</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a4426ee86762ccc849bdbb1aeb095de32</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isMatch</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a6efe721063990764828afc4f384e665a</anchor>
      <arglist>(uint port) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isMaleMatch</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a0c76569c464cf0696998fedca37e8cae</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isFemaleMatch</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>abf36e482e91278bb59eb545f1a5a796b</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isThru</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a2e719bd101b5d50d3e395322f954935d</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isThruMM</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a0e0c315bfb003d1e502f8d5be32a88c1</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isThruMF</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>ad859b59d24770cd5105e2cec1140884a</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isThruFF</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>ad8e53509a1ac250d0ececb3bd1a10e59</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isThru</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>aca57133290ed96f316722a7ab6776c5e</anchor>
      <arglist>(uint port1, uint port2) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isThru</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a8d1e63be8bb2748f1bfb9c53954869be</anchor>
      <arglist>(ConnectorGender gender1, ConnectorGender gender2) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isTouchstone</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a9a2984901961b1ad202b7373c9bf1a2a</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isModel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a588bfe3a8e03dac74767755f1852c542</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isSameModel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>afda3432ec292cc5fd8d7f6286aacff67</anchor>
      <arglist>(const VnaCalStandard &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>VnaStandardType</type>
      <name>type</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a29eb9c4d2177b6b5862e01d11e526523</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>minimumFrequency_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>af335863b3623b329e1535756bcd6737f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>maximumFrequency_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a73d5dbbed152c99013ce8f7217f13124</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>port</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a54e463f81dfc412c50dd4d7e26903433</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>port1</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>ab7448f7cff53dd0e661f9be4fea84aff</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>port2</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a760296cb8c0237a090bd971349acf8f0</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>Connector</type>
      <name>connector</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a40ebe6360163e4300080bd2f202bc027</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>Connector</type>
      <name>connector1</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a2324cc66108138a282c6fb698a889393</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>Connector</type>
      <name>connector2</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a3fb5a77a44175148609241b326591053</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>ConnectorGender</type>
      <name>gender</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>afbe0331cca4e8a65607c498ecb01ea60</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>ConnectorGender</type>
      <name>gender1</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a09b59684bd0cebc0b9355130b18aeb1c</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>ConnectorGender</type>
      <name>gender2</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a9b2fe4e7bf569926747a9d5351c83c91</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>label</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a9acc60996c9e03257803daf0176fb1ff</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>touchstone</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a42c399fa3751c331d2b858018817764a</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setType</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a82d37599bb65e253237d282bb9779159</anchor>
      <arglist>(VnaStandardType type)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setMinimumFrequency</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>ab2f56337ecc21f9dbc5fc76f2578ee7d</anchor>
      <arglist>(double frequency_Hz)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setMaximumFrequency</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>ac11610d3b873bed108afbd925b337151</anchor>
      <arglist>(double frequency_Hz)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>ac9fd5562a9b6c826cf70498b154f81cb</anchor>
      <arglist>(uint port)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPorts</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a9d90ac2bba4b2382c5fea90f6590075d</anchor>
      <arglist>(uint port1, uint port2)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setConnector</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>aafe1803eaea05c0860c476a1ad2fdb3f</anchor>
      <arglist>(Connector connector)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setConnectors</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a9f209c77f70b3ac6a0a950e515a4b469</anchor>
      <arglist>(Connector connector1, Connector connector2)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setLabel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>adbee8ee5ce0807424c561759be441a6f</anchor>
      <arglist>(QString label)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setTouchstoneFile</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>ac463ef74307b563dd38518301f3d773a</anchor>
      <arglist>(QString path)</arglist>
    </member>
    <member kind="function">
      <type>VnaStandardModel</type>
      <name>model</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a069259a93665ad932f162a7fe315e2c7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setOpenModel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a92dfe16522eb33cf873834d74bfc956c</anchor>
      <arglist>(VnaStandardModel model)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setOpenModel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>ad6b9db7c7efe40f1ab622a97675a4c18</anchor>
      <arglist>(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms, double C0_fF, double C1_fF_per_GHz, double C2_fF_per_GHz2, double C3_fF_per_GHz3)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setOpenModel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a6c86d8fa9e6478d821ef6b5925a7cb41</anchor>
      <arglist>(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms, double C0_fF, double C1_fF_per_GHz, double C2_fF_per_GHz2, double C3_fF_per_GHz3, double L0_pH, double L1_pH_per_GHz, double L2_pH_per_GHz2, double L3_pH_per_GHz3, double R_Ohms)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setShortModel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a0fbb7a4f69a69dd797cf5d363e5c671e</anchor>
      <arglist>(VnaStandardModel model)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setShortModel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a96f4144487cca562d42506db54e943dc</anchor>
      <arglist>(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms, double L0_pH, double L1_pH_per_GHz, double L2_pH_per_GHz2, double L3_pH_per_GHz3)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setShortModel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a01ea6f46cc1950b196e430a00c432a4a</anchor>
      <arglist>(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms, double C0_fF, double C1_fF_per_GHz, double C2_fF_per_GHz2, double C3_fF_per_GHz3, double L0_pH, double L1_pH_per_GHz, double L2_pH_per_GHz2, double L3_pH_per_GHz3, double R_Ohms)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setMatchModel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a868f73fb7968b95e3a5984f42068e99f</anchor>
      <arglist>(VnaStandardModel model)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setMatchModel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a959c6976a7f845ec8d377567e6991a08</anchor>
      <arglist>(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setMatchModel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a424f5cc1a367adf02e78f74cf9116a29</anchor>
      <arglist>(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms, double C0_fF, double C1_fF_per_GHz, double C2_fF_per_GHz2, double C3_fF_per_GHz3, double L0_pH, double L1_pH_per_GHz, double L2_pH_per_GHz2, double L3_pH_per_GHz3, double R_Ohms)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setReflectModel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>abc3d5d88fb0d82bfed73f9254c5d28cc</anchor>
      <arglist>(VnaStandardModel model)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setReflectModel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a99c338824ee5317bfdb5eec4516d6685</anchor>
      <arglist>(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms, double C0_fF, double C1_fF_per_GHz, double C2_fF_per_GHz2, double C3_fF_per_GHz3, double L0_pH, double L1_pH_per_GHz, double L2_pH_per_GHz2, double L3_pH_per_GHz3, double R_Ohms)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setThruModel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>aeb0f18b7f473e17dc2ffa2086f7ccf2c</anchor>
      <arglist>(VnaStandardModel model)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setThruModel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>aea89e1839b9cadab754c5bf672a10aae</anchor>
      <arglist>(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setLineModel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a203dd4be8f11243cf71b080b6f6bc921</anchor>
      <arglist>(VnaStandardModel model)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setLineModel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a1526e7d7a11423822cbd236be30ef98f</anchor>
      <arglist>(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setLine2Model</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>aba4358d88d544a1a66c4ea9a8a2b1226</anchor>
      <arglist>(VnaStandardModel model)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setLine2Model</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>aad7a8a555b63d96a75bcabde065c0eb1</anchor>
      <arglist>(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setLine3Model</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>aa33a68516fb3e818c717f04553100533</anchor>
      <arglist>(VnaStandardModel model)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setLine3Model</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a7975a723cbc645552bf102ec02648be7</anchor>
      <arglist>(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setSymmetricNetworkModel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>af45043a8f1461fe974b925c329bfe88b</anchor>
      <arglist>(VnaStandardModel model)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setSymmetricNetworkModel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>aa28e5ee860f3b2eb3dfde120d64ee632</anchor>
      <arglist>(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setSymmetricNetworkModel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a93f9e9789da198a4dc1423ed34373ff3</anchor>
      <arglist>(double e_length_m, double loss_dB_per_Sqrt_Hz, double Z0_Ohms, double C0_fF, double C1_fF_per_GHz, double C2_fF_per_GHz2, double C3_fF_per_GHz3, double L0_pH, double L1_pH_per_GHz, double L2_pH_per_GHz2, double L3_pH_per_GHz3)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDirectConnection</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>aca268c5221558bac094c27e646c502f4</anchor>
      <arglist>(double Z0_Ohms)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>clear</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>ac8bb3912a3ce86b15842e79d0b421204</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>clearPorts</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a1515b7f16c67389474f533fec9ab6f61</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>clearConnectors</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>af3cf8e1deb00399a95c2970a5da33dc5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>ae50bfa34883c0e5ba9af6719d0da2ed3</anchor>
      <arglist>(const VnaCalStandard &amp;other)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static QStringList</type>
      <name>displayText</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a36db2c809a818f9c696bc18b45ce6724</anchor>
      <arglist>(const QVector&lt; VnaCalStandard &gt; &amp;standards)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>sort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>ace23468d67cf1b2b773d7bdc7cdc4a1e</anchor>
      <arglist>(Connector &amp;connector1, Connector &amp;connector2)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>sort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a0c6c2b78933281925c98d9b2e715a594</anchor>
      <arglist>(ConnectorGender &amp;gender1, ConnectorGender &amp;gender2)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>sort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a4a9342a5b548dfd45fcaa415fc05ac7e</anchor>
      <arglist>(uint &amp;port1, uint &amp;port2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>a6888f1003222efc185fc962a6786d9af</anchor>
      <arglist>(const VnaCalStandard &amp;right, const VnaCalStandard &amp;left)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_standard.html</anchorfile>
      <anchor>ae2d1af1697179fcdc95de980965fb6cc</anchor>
      <arglist>(const VnaCalStandard &amp;right, const VnaCalStandard &amp;left)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaCalUnit</name>
    <filename>class_rsa_toolbox_1_1_vna_cal_unit.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaCalUnit</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_unit.html</anchorfile>
      <anchor>a1e90b5fbc48698adfa511f460702f663</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaCalUnit</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_unit.html</anchorfile>
      <anchor>ac26b44c38376fae3ff546a82cfa11369</anchor>
      <arglist>(const VnaCalUnit &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaCalUnit</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_unit.html</anchorfile>
      <anchor>ae886cafb3e731c9614f2843ee652211d</anchor>
      <arglist>(Vna *vna, QString id, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cal_unit.html</anchorfile>
      <anchor>a18edc54202b62041bb6dfd897b211ccd</anchor>
      <arglist>(VnaCalUnit const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaChannel</name>
    <filename>class_rsa_toolbox_1_1_vna_channel.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaChannel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a42c1f7ab205006c53a335212856ef77f</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaChannel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a7d695dc59eafb320bc777c1031380603</anchor>
      <arglist>(VnaChannel const &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaChannel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a1bfcea0d30fe8eda50faeb05ff7a8685</anchor>
      <arglist>(Vna *_vna, uint index, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>index</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>afd04c3c57dc95661658ec079c3a90c06</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>name</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>aee2dd8a62805e14b9f0b407a27159117</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setName</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a6220fae15759fd0fa7d75e415df34e83</anchor>
      <arglist>(QString name)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; uint &gt;</type>
      <name>diagrams</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>aa49393813f1cf620661930fc4ad70d3f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QStringList</type>
      <name>traces</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a43cb9ed8da7e6710f50b5402792ac7e6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>startSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>adaf9645bebbc92214ecbc4c2bfec691b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>numberOfSweeps</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a772da14cb1ef567def4b30a6287d905a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setNumberOfSweeps</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a8b921abbc651989b8bdf8d803e16479e</anchor>
      <arglist>(uint sweeps)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isSweepOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a5d83f85adab5cf18a9e8a3481586f8a7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isSweepOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a25caab90f4264acffadd18d9fa5ac599</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>sweepOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a502f6157a83e166d76cb5a651aa5af08</anchor>
      <arglist>(bool isOn=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>sweepOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>ad5208a593a114a6bed990844b4baaad5</anchor>
      <arglist>(bool isOff=true)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isContinuousSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a7c830474b849344b231d4057868e5e66</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isManualSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a44b621ba60bd309258a3c1345d51aab4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>continuousSweepOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a57a0f55aa0a1d9a707aeb48c1c5a4ab9</anchor>
      <arglist>(bool isOn=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>manualSweepOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a6f0b64776e9418a4afbf301e476e08b4</anchor>
      <arglist>(bool isOn=true)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isLinearSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a24f561b18ffec363888f4ce780481eaf</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isLogarithmicSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>ada8399238a7a4e3e8d65629e7e0c4273</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isSegmentedSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>ad5d8ff98c82a1a266134875d0c1029ce</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isPowerSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>abbdc3eefb3f988225d180719c6a99553</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isCwSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a742829bf2ec832da4714546aa1fadd5c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isTimeSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a3ccc7d8de8abc24fcfdf3a7a485001f8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaSweepType</type>
      <name>sweepType</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a37df4189af5bfff7ad4aa76741f97608</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setSweepType</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a73e90e789be356accbdbfaa6a58ed966</anchor>
      <arglist>(VnaSweepType sweepType)</arglist>
    </member>
    <member kind="function">
      <type>VnaLinearSweep &amp;</type>
      <name>linearSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a97c44f3bc81bbd605aeded25e538d8c6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaLinearSweep *</type>
      <name>takeLinearSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>ae40417b1c279fff4dfbe7ca7916f281e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaLogSweep &amp;</type>
      <name>logSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>ad1d0ac75784e633ae64e039477988022</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaLogSweep *</type>
      <name>takeLogSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>acc85799614780ecb7793ff2bd01ca343</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaSegmentedSweep &amp;</type>
      <name>segmentedSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a9631bd2f1d9ef7df04d782a33e1786a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaSegmentedSweep *</type>
      <name>takeSegmentedSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a7244742260017e54cb635b0b9569948b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaPowerSweep &amp;</type>
      <name>powerSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a657c4a8ff0c8047e0b65ad590c2fcbfd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaPowerSweep *</type>
      <name>takePowerSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>ae2f3324beaa8ecdd75a4888f7d7183b4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaCwSweep &amp;</type>
      <name>cwSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a19b4da6f0d2a9356d60fc73198e8b057</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaCwSweep *</type>
      <name>takeCwSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a8f0285b65449d18e15e91ee74d33e557</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaTimeSweep &amp;</type>
      <name>timeSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>ada006d487c4f39beab2aa2b5159c7277</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaTimeSweep *</type>
      <name>takeTimeSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>aa328175dc8ba0b5197c0ba9ce9a3fcf2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>numberOfLogicalPorts</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>af216e4ee57f16d91d2b32c0cf171b58f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isSingleEndedPort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>adf19b9e625f53a0c458d68cf174f2bc2</anchor>
      <arglist>(uint logicalPort)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>physicalPort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a4b05497645be1773316f9f4ae15b97a7</anchor>
      <arglist>(uint logicalPort)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isBalancedPort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>adcb28b970577b5edda9b0f20762cd8a4</anchor>
      <arglist>(uint logicalPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>physicalPorts</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>ad354f2e6076001700285f33247db5101</anchor>
      <arglist>(uint logicalPort, uint &amp;physicalPort1, uint &amp;physicalPort2)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>createSingleEndedPort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a5591b40fb1ecdec431608de012490970</anchor>
      <arglist>(uint logicalPort, uint physicalPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>createBalancedPort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a3465465d07d5e096e340dd4bd06b707d</anchor>
      <arglist>(uint logicalPort, uint physicalPort1, uint physicalPort2)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteBalancedPort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a644beabfba8aacb002240e1bfb5462eb</anchor>
      <arglist>(uint logicalPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteBalancedPorts</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>ad1cac57cb956cd52bbbc329e156f39f1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isUserDefinedPort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>adf64d0861311085311db623b83e127e5</anchor>
      <arglist>(uint physicalPort)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotUserDefinedPort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>ae89cea73d76dc4b193a1f33b74099ae7</anchor>
      <arglist>(uint physicalPort)</arglist>
    </member>
    <member kind="function">
      <type>VnaUserDefinedPort</type>
      <name>userDefinedPort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a34549ad8f86ab1bff590b36f059cfafc</anchor>
      <arglist>(uint physicalPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setUserDefinedPort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a4e2b5ffd558f8033d56ec38964e30fc7</anchor>
      <arglist>(uint physicalPort, VnaUserDefinedPort userDefinedPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteUserDefinedPort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a6623587420a21a98db218fc43b63acc1</anchor>
      <arglist>(uint physicalPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteUserDefinedPorts</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>aff66b0016dd231642a695ce12ca47c48</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaAveraging &amp;</type>
      <name>averaging</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a054f6afdc1ed2535960bfe6cf90e4e9d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isCalibrated</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a10cdc52aaea7c8fc0b21d1ef3a9e9d6e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isCalGroup</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a6f1f6e4064a7dbd30b5254f188b11daf</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>saveCalibration</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>ae3c00dc9706b2a524e6cc901ab5b232b</anchor>
      <arglist>(QString calGroup)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCalGroup</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a73db6c7f78413379050ef4e5f7945701</anchor>
      <arglist>(QString calGroup)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>calGroup</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a47e13e945e580c28ecb77e7961e086e6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>calGroupFile</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>ab3f5140e5ea7b7a8f79bcaf97cf8b765</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>dissolveCalGroup</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>ae887791e919cc0582faae650c1116d10</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaCorrections &amp;</type>
      <name>corrections</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a0a8239220cad726a1808caf733e984d4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaCalibrate &amp;</type>
      <name>calibrate</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a85ef0d9299e04b6ad4c9448c444fc206</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaCalibrate *</type>
      <name>takeCalibrate</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a17813337ac4d01f73de6d925918c31a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_channel.html</anchorfile>
      <anchor>a292ca03a043b857aa4e9f08a2eb089dc</anchor>
      <arglist>(VnaChannel const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaCorrections</name>
    <filename>class_rsa_toolbox_1_1_vna_corrections.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaCorrections</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>af0731b2392e1f6f02d78047f9cb9ab04</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaCorrections</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>af47c7513ac31496ce8652354e1765cb8</anchor>
      <arglist>(VnaCorrections &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaCorrections</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>aeec76f0ee3b555f24626591de663e556</anchor>
      <arglist>(Vna *vna, VnaChannel *channel, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaCorrections</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>aacadb276e7ed8cf36aecac3d79f861e5</anchor>
      <arglist>(Vna *vna, uint channelIndex, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>a3909f77aa50b8f46ccadc196178a07a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>a45cb35cce9c006e0f1428934f6d828cb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isPresent</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>ae66473ae8c9abee2961692c5473ab1cd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotPresent</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>a78f6b37c5f9c9de89b3210e9f61cb9a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isInterpolated</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>a63b09953bbe7677d9eedcae2b4d3c666</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotInterpolated</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>ad992522d8bbcd1ddee5303dbf345bede</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>on</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>af5ab223c4aa62b4fc1bcc3a166bc2517</anchor>
      <arglist>(bool isOn=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>off</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>a785abb1dda82d2aa86dca3b47ad8c5db</anchor>
      <arglist>(bool isOff=true)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>calGroup</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>a47e13e945e580c28ecb77e7961e086e6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCalGroup</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>a73db6c7f78413379050ef4e5f7945701</anchor>
      <arglist>(QString calGroup)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>saveToCalGroup</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>a256b5234b73e122040a9e5b5246ee9ff</anchor>
      <arglist>(QString calGroup)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>dissolveCalGroupLink</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>af9210094cea5a937b7a5f5e771ac0e3d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>clear</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>ac8bb3912a3ce86b15842e79d0b421204</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaCalType</type>
      <name>calibrationType</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>ac18b4d367aed615ccbf6c7794228470d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaSweepType</type>
      <name>sweepType</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>a37df4189af5bfff7ad4aa76741f97608</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; uint &gt;</type>
      <name>ports</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>ac0e2cc29d1ddf19a95d69888f9c15195</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>points</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>acbdc0bd270e1acb2eee1f8c9a7f9a85d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>startFrequency_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>a9f9ac6fbd537bac5ef248f5b53fdf279</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>stopFrequency_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>ada869bfd357d80ea884bf7c822906329</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>power_dBm</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>aed9bf0f8af990a0e5169bcbd4c6fda0e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>directivity</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>a38dd5aa70137810f69f129d4c0a3c9df</anchor>
      <arglist>(uint outputPort, uint inputPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDirectivity</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>a15019ba28b89e00acc11e4fc90ae23d6</anchor>
      <arglist>(ComplexRowVector corrections, uint outputPort, uint inputPort)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>sourceMatch</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>a78330ff1a25e01a99647bc02cf04e90c</anchor>
      <arglist>(uint outputPort, uint inputPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setSourceMatch</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>acbe76af6d143849cf3bd3485db8be3cc</anchor>
      <arglist>(ComplexRowVector corrections, uint outputPort, uint inputPort)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>reflectionTracking</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>a44b1572eea37fdcaab3eccef28ce0b0d</anchor>
      <arglist>(uint outputPort, uint inputPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setReflectionTracking</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>a781e021b20a15a5680607e90617d5e40</anchor>
      <arglist>(ComplexRowVector corrections, uint outputPort, uint inputPort)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>loadMatch</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>a8022002532bb645b57a7204ab705b0d1</anchor>
      <arglist>(uint outputPort, uint inputPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setLoadMatch</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>a67d65f31c357351a45d1e80520b03d66</anchor>
      <arglist>(ComplexRowVector corrections, uint outputPort, uint inputPort)</arglist>
    </member>
    <member kind="function">
      <type>ComplexRowVector</type>
      <name>transmissionTracking</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>ad3392508fc15b93d27ba91ff16bda253</anchor>
      <arglist>(uint outputPort, uint inputPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setTransmissionTracking</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>ace87f8f0c756763e9ce50324b9e62acb</anchor>
      <arglist>(ComplexRowVector corrections, uint outputPort, uint inputPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_corrections.html</anchorfile>
      <anchor>a257927904d3edb1a2f78448700848dba</anchor>
      <arglist>(VnaCorrections const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaCwSweep</name>
    <filename>class_rsa_toolbox_1_1_vna_cw_sweep.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaCwSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cw_sweep.html</anchorfile>
      <anchor>ab90bcae14d2901b085b895e575e9f5a3</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaCwSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cw_sweep.html</anchorfile>
      <anchor>ad6a7e2ea77aecf8bac9e93569b8adc18</anchor>
      <arglist>(VnaCwSweep &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaCwSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cw_sweep.html</anchorfile>
      <anchor>abaa85ae2913d16a95e40eca96ab0ca47</anchor>
      <arglist>(Vna *vna, VnaChannel *channel, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaCwSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cw_sweep.html</anchorfile>
      <anchor>afe6936f6a4b48b5c2152fb4c42225f46</anchor>
      <arglist>(Vna *vna, uint channelIndex, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>points</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cw_sweep.html</anchorfile>
      <anchor>acbdc0bd270e1acb2eee1f8c9a7f9a85d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPoints</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cw_sweep.html</anchorfile>
      <anchor>a865b3daabe5358c3695484b9ceaf8028</anchor>
      <arglist>(uint numberOfPoints)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>frequency_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cw_sweep.html</anchorfile>
      <anchor>a91acfcdb00405d0e48878c2bc69caa14</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setFrequency</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cw_sweep.html</anchorfile>
      <anchor>a970ff5fa599be106d0aa20e4ee9ca474</anchor>
      <arglist>(double frequency, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>power_dBm</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cw_sweep.html</anchorfile>
      <anchor>aed9bf0f8af990a0e5169bcbd4c6fda0e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPower</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cw_sweep.html</anchorfile>
      <anchor>aac822adb781e223a96898409db296a43</anchor>
      <arglist>(double power_dBm)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>ifBandwidth_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cw_sweep.html</anchorfile>
      <anchor>a669ad1da20ac86ec3e7a6b3220b785a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setIfBandwidth</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cw_sweep.html</anchorfile>
      <anchor>ae47765726943314de1d1a955e7f73f8e</anchor>
      <arglist>(double bandwidth, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_cw_sweep.html</anchorfile>
      <anchor>ae655a51737c2ea518b957abb3890f28a</anchor>
      <arglist>(VnaCwSweep const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaDiagram</name>
    <filename>class_rsa_toolbox_1_1_vna_diagram.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaDiagram</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_diagram.html</anchorfile>
      <anchor>aba9de54d77b745e56c2e5ac6039745fb</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaDiagram</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_diagram.html</anchorfile>
      <anchor>aef2bbf23f7e3d47e71a4cbf5f938a165</anchor>
      <arglist>(const VnaDiagram &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaDiagram</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_diagram.html</anchorfile>
      <anchor>ac5905e3e771ba4fc0cfde356a1f3d5e9</anchor>
      <arglist>(Vna *vna, uint index, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; uint &gt;</type>
      <name>channels</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_diagram.html</anchorfile>
      <anchor>afea6252754a9fbd157f2d927ad88470b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QStringList</type>
      <name>traces</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_diagram.html</anchorfile>
      <anchor>a43cb9ed8da7e6710f50b5402792ac7e6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteTraces</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_diagram.html</anchorfile>
      <anchor>ab034ce3db42f3c2f7ac4ab94d3c3e1f8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>title</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_diagram.html</anchorfile>
      <anchor>a0c7009d5678fb28509570139b1bd2baf</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setTitle</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_diagram.html</anchorfile>
      <anchor>ab7444cbc31917a6cdd0c60b42f9dc019</anchor>
      <arglist>(QString title)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>autoscale</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_diagram.html</anchorfile>
      <anchor>a42080b87976a6e7f1945e996b45d4df3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setYAxisMinimum</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_diagram.html</anchorfile>
      <anchor>a05a1cf83908ac03f85667ae3ea8d1dd8</anchor>
      <arglist>(double min)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setYAxisMaximum</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_diagram.html</anchorfile>
      <anchor>a13fab992a1eb6af96c2a9da22d232624</anchor>
      <arglist>(double max)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setYAxis</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_diagram.html</anchorfile>
      <anchor>aa700883fb370926a7696daf8339927c9</anchor>
      <arglist>(double min, double max)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_diagram.html</anchorfile>
      <anchor>aba0e3a4507353cfc8c3ad70981971279</anchor>
      <arglist>(VnaDiagram const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaFileSystem</name>
    <filename>class_rsa_toolbox_1_1_vna_file_system.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaFileSystem</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>ae37eb2f93141ebc884b38950aba7ab53</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaFileSystem</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>a777d4e37c87890b199fefaf935141420</anchor>
      <arglist>(VnaFileSystem &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaFileSystem</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>a1ae9468d892f153f5490123b2b1745d1</anchor>
      <arglist>(Vna *_vna, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isFile</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>ad13e161384b6ef1326912e8e08790ac1</anchor>
      <arglist>(QString pathName)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotFile</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>aa646c8e0e223127838023eb45c120bb7</anchor>
      <arglist>(QString pathName)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isDirectory</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>a88261485c1708f6f80a297184511f2ea</anchor>
      <arglist>(QString pathName)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotDirectory</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>af41e25cf546ca3878d3185fb7ada68ad</anchor>
      <arglist>(QString pathName)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isFreeSpace</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>a3d0d6b99422a8ef8b09b61d7583bb22c</anchor>
      <arglist>(quint64 bytes)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isFreeSpace</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>a922316262a1db857d5c3d5a2091ac7c9</anchor>
      <arglist>(QString path, quint64 bytes)</arglist>
    </member>
    <member kind="function">
      <type>QStringList</type>
      <name>files</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>a2ec428a3022d9177fa4ee6498ed55473</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QStringList</type>
      <name>files</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>a740879343e70c0472084b73c80888b03</anchor>
      <arglist>(QString path)</arglist>
    </member>
    <member kind="function">
      <type>QStringList</type>
      <name>directories</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>abfbabed179d729ef26c7da81c820f5ac</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QStringList</type>
      <name>directories</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>a50e01624376ad8c4c6cc80fdccb8d4e0</anchor>
      <arglist>(QString path)</arglist>
    </member>
    <member kind="function">
      <type>quint64</type>
      <name>freeSpace_Bytes</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>a4b37e4ce939bc30aac4fcf1e42353e01</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>quint64</type>
      <name>freeSpace_Bytes</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>a05a1eaa2e74c9d8fe6c78c98c2a7c615</anchor>
      <arglist>(QString path)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>fileSize_Bytes</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>a5d180755743b20c590c399a62350eb66</anchor>
      <arglist>(QString pathName)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>directory</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>a0b2ce6541f7a50ec7443e0d8b0f9d75c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>directory</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>a3219952936442ae99ff3d556979ff132</anchor>
      <arglist>(VnaDirectory directory)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>changeDirectory</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>a0921c62d2c2baaf0460e0c1e5d6499bd</anchor>
      <arglist>(QString path)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>changeDirectory</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>a33d52efb43aa29ab5f866b4ff9f199d5</anchor>
      <arglist>(VnaDirectory directory)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>createDirectory</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>a0a90456916cce5402bbdc0c4b54ab171</anchor>
      <arglist>(QString pathName)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>moveFile</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>a94eb41b7c63d27f170a1c5c5d1ebdce8</anchor>
      <arglist>(QString sourcePathName, QString destinationPathName)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>copyFile</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>aa2bd5fa44bba5d7949ef187f0d81b975</anchor>
      <arglist>(QString sourcePathName, QString destinationPathName)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteFile</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>ae696c7af6fdedf4ed235043b5d18c715</anchor>
      <arglist>(QString pathName)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteFiles</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>a96df2158e391c42a7689732c96beec76</anchor>
      <arglist>(QStringList pathNames)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteFiles</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>a704517af6b4a0c9f1196a3be9e61abd7</anchor>
      <arglist>(QString path)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteFiles</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>a71e12ee697e9ea3f04f3125ee24eb9cd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteDirectory</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>a7aa1220eb49348a3e856a3f3f6fe50bb</anchor>
      <arglist>(QString pathName)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>uploadFile</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>aedbb2623e79eb4bd615ab0f25be03257</anchor>
      <arglist>(QString sourcePathName, QString destinationPathName)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>uploadFile</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>a8032bce8508a48552c32a4c651bb163f</anchor>
      <arglist>(QString sourcePathName, QString destinationFilename, VnaDirectory destinationDirectory)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>downloadFile</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>a9cb3a46e399ef4a7831a2bcbde4674c3</anchor>
      <arglist>(QString sourcePathName, QString destinationPathName)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>downloadFile</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>ad0efb9ab51ff4bf8a49c6672a5a41c9e</anchor>
      <arglist>(QString sourcePathName, QString destinationPathName, uint bufferSize_B)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>downloadFile</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>abc5528fe28595abf6b6c99285c33be9c</anchor>
      <arglist>(QString sourceFilename, VnaDirectory sourceDirectory, QString destinationPathName)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>downloadFile</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>aad8554de6a266fbf6a1b38b43a1acabb</anchor>
      <arglist>(QString sourceFilename, VnaDirectory sourceDirectory, QString destinationPathName, uint bufferSize_B)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_file_system.html</anchorfile>
      <anchor>a4c1dbf3639064ce227c971e2a99740f8</anchor>
      <arglist>(VnaFileSystem const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaLinearSweep</name>
    <filename>class_rsa_toolbox_1_1_vna_linear_sweep.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaLinearSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>a104003b5cd3376f57f7ea21d1201cd97</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaLinearSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>a6faa279b478d14e22da2484073d08233</anchor>
      <arglist>(VnaLinearSweep &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaLinearSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>ae8f51d6d0cf71932947e53c360d1d9bb</anchor>
      <arglist>(Vna *vna, VnaChannel *channel, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaLinearSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>aee07ba7283603188e117cee5e28f12ce</anchor>
      <arglist>(Vna *vna, uint channelIndex, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>points</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>acbdc0bd270e1acb2eee1f8c9a7f9a85d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPoints</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>a865b3daabe5358c3695484b9ceaf8028</anchor>
      <arglist>(uint numberOfPoints)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>start_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>a413388b196a6bcd75bb8ee9284d56af4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setStart</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>a5ac411e306b822644e9740e62329b90c</anchor>
      <arglist>(double frequency, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>stop_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>a52c971759a84fc28fa0735ce04b3e1fc</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setStop</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>a417769e36a3253632c77c5ee09a89698</anchor>
      <arglist>(double frequency, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>center_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>aaeaeb032dfc1d3d3c1378ff6ae207d15</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCenter</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>a37ba7a5f94d5fa96e168179b540e0e10</anchor>
      <arglist>(double frequency, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>span_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>a585971270a27be9dcc14f5eed19481c7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setSpan</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>a78e656f7e7de344ecb4db92b5494facc</anchor>
      <arglist>(double frequencyRange, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>spacing_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>a6ef67446697dc64c359820fccbbfbc0b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setSpacing</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>aeb2e5fbd7922db4b517cedf0666a9f44</anchor>
      <arglist>(double frequencySpacing, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>frequencies_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>a6bdb7349d9336d3c5eb00616f78c202a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>power_dBm</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>aed9bf0f8af990a0e5169bcbd4c6fda0e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPower</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>aac822adb781e223a96898409db296a43</anchor>
      <arglist>(double power_dBm)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>ifBandwidth_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>a669ad1da20ac86ec3e7a6b3220b785a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setIfbandwidth</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>a350d457150f3219b2c880083afb2d63c</anchor>
      <arglist>(double bandwidth, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; uint &gt;</type>
      <name>sParameterGroup</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>ac7a50334398a7820485919ddb24150dd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setSParameterGroup</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>ae03d74323281e5fac2ac8c60272add1c</anchor>
      <arglist>(QVector&lt; uint &gt; ports)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>clearSParameterGroup</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>af0435978efe0339d462c159ca1b00864</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix3D</type>
      <name>readSParameterGroup</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>a83cd1058a5091918d294e1ba612941ae</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>estimatedSweepTime_s</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>a38c2dda1f527752d1d4a4c4f0774b0ce</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setSweepTime</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>ac67e33d2b920df17a3f648ea8e772976</anchor>
      <arglist>(double time_s)</arglist>
    </member>
    <member kind="function">
      <type>NetworkData</type>
      <name>measure</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>a1139e1760db35d5c1304e8072b289f10</anchor>
      <arglist>(uint port1)</arglist>
    </member>
    <member kind="function">
      <type>NetworkData</type>
      <name>measure</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>a108ba0072a55a62c6d70cfe0aa361b9f</anchor>
      <arglist>(uint port1, uint port2)</arglist>
    </member>
    <member kind="function">
      <type>NetworkData</type>
      <name>measure</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>a269807991452399fc4607e261d60318e</anchor>
      <arglist>(uint port1, uint port2, uint port3)</arglist>
    </member>
    <member kind="function">
      <type>NetworkData</type>
      <name>measure</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>ad99b8de57e97aa43fe5d0d36967389e7</anchor>
      <arglist>(uint port1, uint port2, uint port3, uint port4)</arglist>
    </member>
    <member kind="function">
      <type>NetworkData</type>
      <name>measure</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>a0adcf6cc4450039b97795779197b9792</anchor>
      <arglist>(QVector&lt; uint &gt; ports)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>saveSnp</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>aeb51800fb94ffbf103889dde5bf5f271</anchor>
      <arglist>(QString filePathName, uint port1, ComplexFormat format=REAL_IMAGINARY_COMPLEX)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>saveSnp</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>add280d3d9e3fb1762c6baf162ef21838</anchor>
      <arglist>(QString filePathName, uint port1, uint port2, ComplexFormat format=REAL_IMAGINARY_COMPLEX)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>saveSnp</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>a37c8c052f79dd0b7a8cbef1b20cc8e15</anchor>
      <arglist>(QString filePathName, uint port1, uint port2, uint port3, ComplexFormat format=REAL_IMAGINARY_COMPLEX)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>saveSnp</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>a10eda0f69b2ac7e4342b1c7361ec4511</anchor>
      <arglist>(QString filePathName, uint port1, uint port2, uint port3, uint port4, ComplexFormat format=REAL_IMAGINARY_COMPLEX)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>saveSnp</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>a0328d8a60f7ab434882260a90c8ffc87</anchor>
      <arglist>(QString filePathName, QVector&lt; uint &gt; ports, ComplexFormat format=REAL_IMAGINARY_COMPLEX)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_linear_sweep.html</anchorfile>
      <anchor>a8d62eeccf3f5b70164a58d66e57356df</anchor>
      <arglist>(VnaLinearSweep const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaLogSweep</name>
    <filename>class_rsa_toolbox_1_1_vna_log_sweep.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaLogSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>a7d3c6aba9f34abafbab280063fa31f3b</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaLogSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>a7422421cc25d1ec01a293e649ecf8f54</anchor>
      <arglist>(VnaLogSweep &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaLogSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>a8a804a108085745d3699b016407e9681</anchor>
      <arglist>(Vna *vna, VnaChannel *channel, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaLogSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>a67119e84876f4061b4b2c9a44467dd2b</anchor>
      <arglist>(Vna *vna, uint channelIndex, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>points</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>acbdc0bd270e1acb2eee1f8c9a7f9a85d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPoints</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>a865b3daabe5358c3695484b9ceaf8028</anchor>
      <arglist>(uint numberOfPoints)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>start_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>a413388b196a6bcd75bb8ee9284d56af4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setStart</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>a5ac411e306b822644e9740e62329b90c</anchor>
      <arglist>(double frequency, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>stop_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>a52c971759a84fc28fa0735ce04b3e1fc</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setStop</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>a417769e36a3253632c77c5ee09a89698</anchor>
      <arglist>(double frequency, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; double &gt;</type>
      <name>frequencies_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>aaf0a017e8ef1baa58e87488e548de3b3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>power_dBm</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>aed9bf0f8af990a0e5169bcbd4c6fda0e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPower</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>aac822adb781e223a96898409db296a43</anchor>
      <arglist>(double power_dBm)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>ifBandwidth_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>a669ad1da20ac86ec3e7a6b3220b785a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setIfbandwidth</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>a350d457150f3219b2c880083afb2d63c</anchor>
      <arglist>(double bandwidth, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; uint &gt;</type>
      <name>sParameterGroup</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>ac7a50334398a7820485919ddb24150dd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setSParameterGroup</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>ae03d74323281e5fac2ac8c60272add1c</anchor>
      <arglist>(QVector&lt; uint &gt; ports)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>clearSParameterGroup</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>af0435978efe0339d462c159ca1b00864</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix3D</type>
      <name>readSParameterGroup</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>a83cd1058a5091918d294e1ba612941ae</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>NetworkData</type>
      <name>measure</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>a1139e1760db35d5c1304e8072b289f10</anchor>
      <arglist>(uint port1)</arglist>
    </member>
    <member kind="function">
      <type>NetworkData</type>
      <name>measure</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>a108ba0072a55a62c6d70cfe0aa361b9f</anchor>
      <arglist>(uint port1, uint port2)</arglist>
    </member>
    <member kind="function">
      <type>NetworkData</type>
      <name>measure</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>a269807991452399fc4607e261d60318e</anchor>
      <arglist>(uint port1, uint port2, uint port3)</arglist>
    </member>
    <member kind="function">
      <type>NetworkData</type>
      <name>measure</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>ad99b8de57e97aa43fe5d0d36967389e7</anchor>
      <arglist>(uint port1, uint port2, uint port3, uint port4)</arglist>
    </member>
    <member kind="function">
      <type>NetworkData</type>
      <name>measure</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>a0adcf6cc4450039b97795779197b9792</anchor>
      <arglist>(QVector&lt; uint &gt; ports)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_log_sweep.html</anchorfile>
      <anchor>ada4db23d6f8b878bd6dfdac76430a9ea</anchor>
      <arglist>(VnaLogSweep const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaMarker</name>
    <filename>class_rsa_toolbox_1_1_vna_marker.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaMarker</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_marker.html</anchorfile>
      <anchor>aa695231f087265c9a0b62e467e67bddc</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaMarker</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_marker.html</anchorfile>
      <anchor>a6505b2c52b145cb87d5681072525502a</anchor>
      <arglist>(const VnaMarker &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaMarker</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_marker.html</anchorfile>
      <anchor>a9998c759ea4c3a8d842c9c46db6ade03</anchor>
      <arglist>(Vna *vna, VnaTrace *trace, uint index, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaMarker</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_marker.html</anchorfile>
      <anchor>a29c1352a70b5708de4b2535f4fb59537</anchor>
      <arglist>(Vna *vna, QString traceName, uint index, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>name</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_marker.html</anchorfile>
      <anchor>aee2dd8a62805e14b9f0b407a27159117</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setName</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_marker.html</anchorfile>
      <anchor>a6220fae15759fd0fa7d75e415df34e83</anchor>
      <arglist>(QString name)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isDeltaOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_marker.html</anchorfile>
      <anchor>a24045a320df0c2dadac21e6578017a6e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isDeltaOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_marker.html</anchorfile>
      <anchor>aefd7ce5e2f8fff1f245cae5cff39b496</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deltaOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_marker.html</anchorfile>
      <anchor>ab82ef0b332c9fa229b3a152358aa65f7</anchor>
      <arglist>(bool isOn=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deltaOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_marker.html</anchorfile>
      <anchor>a6ecdd3d6c7fc08caf85755a1cf28013c</anchor>
      <arglist>(bool isOff=true)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>y</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_marker.html</anchorfile>
      <anchor>a52c7eae49e9d0d75c6cc38f61ed526f2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>x</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_marker.html</anchorfile>
      <anchor>a1d181ea8ec179ff8046ef6cf2a8aa232</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>coordinates</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_marker.html</anchorfile>
      <anchor>ada220dcb18bad3f30ae11714ff06c405</anchor>
      <arglist>(double &amp;x, double &amp;y)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setX</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_marker.html</anchorfile>
      <anchor>aebaa65e5092d73ad02999226a63bb126</anchor>
      <arglist>(double x, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>searchForMax</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_marker.html</anchorfile>
      <anchor>a555f6e64734dd5e45d8b83f85ac38a22</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>searchForMin</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_marker.html</anchorfile>
      <anchor>ad1236202839647657aa0cf65c069b942</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>searchFor</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_marker.html</anchorfile>
      <anchor>aadc358732fa914ff77c5bcaf323f5b26</anchor>
      <arglist>(double y)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>searchRightFor</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_marker.html</anchorfile>
      <anchor>af93f5bf414f2bc9cf8f6f1d523ed3a8b</anchor>
      <arglist>(double y)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>searchRightForPeak</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_marker.html</anchorfile>
      <anchor>addc3713ed3bc2db4050ca8a74421e46b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>searchLeftFor</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_marker.html</anchorfile>
      <anchor>abf7271681a06696b38ee9160076c7880</anchor>
      <arglist>(double y)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>searchLeftForPeak</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_marker.html</anchorfile>
      <anchor>a7faf682534e094894cac09cbed8c5512</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setReferenceMarker</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_marker.html</anchorfile>
      <anchor>a01c679093a777c2298d11093acce4658</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>measureBandpassFilter</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_marker.html</anchorfile>
      <anchor>aef830661e4ae111cbb2633acbf237697</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_marker.html</anchorfile>
      <anchor>acf870463e4e8323487f637b6d7b3ecef</anchor>
      <arglist>(VnaMarker const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaPowerCalibrate</name>
    <filename>class_rsa_toolbox_1_1_vna_power_calibrate.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaPowerCalibrate</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_calibrate.html</anchorfile>
      <anchor>a9835b9319fa1015defd1b4ffe3154a43</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaPowerCalibrate</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_calibrate.html</anchorfile>
      <anchor>a48537a82a82b0c2be1f78b9ff05cd30c</anchor>
      <arglist>(VnaPowerCalibrate &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaPowerCalibrate</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_calibrate.html</anchorfile>
      <anchor>af15c49d8f09e1ebb0c234206e0279c17</anchor>
      <arglist>(Vna *vna, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaPowerCalibrate</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_calibrate.html</anchorfile>
      <anchor>acd8c75f2007fc1895e287b292aa0555c</anchor>
      <arglist>(Vna *vna, VnaChannel *channel, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaPowerCalibrate</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_calibrate.html</anchorfile>
      <anchor>abdf7a889ab542562865a530c4608f956</anchor>
      <arglist>(Vna *vna, uint channelIndex, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isRawDataKept</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_calibrate.html</anchorfile>
      <anchor>a1a229251cac896f1f4cd027588313012</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setConnector</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_calibrate.html</anchorfile>
      <anchor>a5be19415118f23c0d16084a60b90d33a</anchor>
      <arglist>(uint port, Connector connector)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setConnectors</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_calibrate.html</anchorfile>
      <anchor>ab52950f793d3a45b291191bf88ed317f</anchor>
      <arglist>(Connector connector)</arglist>
    </member>
    <member kind="function">
      <type>Connector</type>
      <name>connector</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_calibrate.html</anchorfile>
      <anchor>a4e8c2593d3bd095e75aec52c0c2dc7f9</anchor>
      <arglist>(uint port)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; Connector &gt;</type>
      <name>connectors</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_calibrate.html</anchorfile>
      <anchor>aa5a3dfdd57c9eba8eb08677f32c6f209</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>start</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_calibrate.html</anchorfile>
      <anchor>a1f83eeb39fc58711aba1c5084e46e914</anchor>
      <arglist>(QString calibrationName, uint port)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>keepRawData</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_calibrate.html</anchorfile>
      <anchor>a8b05b89e74abc4abaadda024b6a3cf29</anchor>
      <arglist>(bool isKept=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>apply</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_calibrate.html</anchorfile>
      <anchor>a95067243b72a23863ec07c821797455c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_calibrate.html</anchorfile>
      <anchor>a927d4aec0a61e6c9beff8bb853457f9a</anchor>
      <arglist>(VnaPowerCalibrate const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaPowerCorrections</name>
    <filename>class_rsa_toolbox_1_1_vna_power_corrections.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaPowerCorrections</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_corrections.html</anchorfile>
      <anchor>aab24a893e1716b28e1626eb88ac74728</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaPowerCorrections</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_corrections.html</anchorfile>
      <anchor>aef59ae7fa4c3f8b1c967dba8a468a035</anchor>
      <arglist>(VnaPowerCorrections &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaPowerCorrections</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_corrections.html</anchorfile>
      <anchor>ae1d1bff1c07f3a92d570b9396689a498</anchor>
      <arglist>(Vna *vna, VnaChannel *channel, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaPowerCorrections</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_corrections.html</anchorfile>
      <anchor>a182d26428cd86bc7137e7c0d832d62c8</anchor>
      <arglist>(Vna *vna, uint channelIndex, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_corrections.html</anchorfile>
      <anchor>ab86b0aab2827773e5bc2bb8bd8db9334</anchor>
      <arglist>(uint port)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_corrections.html</anchorfile>
      <anchor>a67a4af230452f136f891fc18a1920d11</anchor>
      <arglist>(uint port)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isPresent</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_corrections.html</anchorfile>
      <anchor>a8c93975ff5a627fdde52895b77101dc5</anchor>
      <arglist>(uint port)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotPresent</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_corrections.html</anchorfile>
      <anchor>a804320bcf2cda87f416ce35589d619e2</anchor>
      <arglist>(uint port)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isInterpolated</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_corrections.html</anchorfile>
      <anchor>af752561ca05cd3b3980e7d4e51ef6e15</anchor>
      <arglist>(uint port)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotInterpolated</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_corrections.html</anchorfile>
      <anchor>a555e2dce3f1064dc0346ae2fea0d8f73</anchor>
      <arglist>(uint port)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>on</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_corrections.html</anchorfile>
      <anchor>aaeb2fcc63f08a520f03b966cb825c704</anchor>
      <arglist>(uint port, bool isOn=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>off</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_corrections.html</anchorfile>
      <anchor>aa36c589566af7344ab5b63c362589539</anchor>
      <arglist>(uint port, bool isOff=true)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>calGroup</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_corrections.html</anchorfile>
      <anchor>a47e13e945e580c28ecb77e7961e086e6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCalGroup</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_corrections.html</anchorfile>
      <anchor>a73db6c7f78413379050ef4e5f7945701</anchor>
      <arglist>(QString calGroup)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>saveToCalGroup</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_corrections.html</anchorfile>
      <anchor>a256b5234b73e122040a9e5b5246ee9ff</anchor>
      <arglist>(QString calGroup)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>dissolveCalGroupLink</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_corrections.html</anchorfile>
      <anchor>af9210094cea5a937b7a5f5e771ac0e3d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>clear</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_corrections.html</anchorfile>
      <anchor>ac8bb3912a3ce86b15842e79d0b421204</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_corrections.html</anchorfile>
      <anchor>ac25543ec857fd9982250165c0d132511</anchor>
      <arglist>(VnaPowerCorrections const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaPowerSweep</name>
    <filename>class_rsa_toolbox_1_1_vna_power_sweep.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaPowerSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_sweep.html</anchorfile>
      <anchor>aa42eba8801bf92f8405e81b2e3f25274</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaPowerSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_sweep.html</anchorfile>
      <anchor>aa87a296af0bc092070a9ea6d2bc94911</anchor>
      <arglist>(VnaPowerSweep &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaPowerSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_sweep.html</anchorfile>
      <anchor>ab19387b1312fdeaa124bd63bc8f59292</anchor>
      <arglist>(Vna *vna, VnaChannel *channel, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaPowerSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_sweep.html</anchorfile>
      <anchor>aacba43fec1ed8219ab0dd48597b019d2</anchor>
      <arglist>(Vna *vna, uint channelIndex, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>points</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_sweep.html</anchorfile>
      <anchor>acbdc0bd270e1acb2eee1f8c9a7f9a85d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPoints</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_sweep.html</anchorfile>
      <anchor>a865b3daabe5358c3695484b9ceaf8028</anchor>
      <arglist>(uint numberOfPoints)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>start_dBm</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_sweep.html</anchorfile>
      <anchor>a05842efd3265d52774d5a5fa1d968eec</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setStart</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_sweep.html</anchorfile>
      <anchor>a48eaea0e837377a088d221e63c177096</anchor>
      <arglist>(double power_dBm)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>stop_dBm</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_sweep.html</anchorfile>
      <anchor>a55c1fa7ec87c8ce4e28715076f3f4a7a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setStop</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_sweep.html</anchorfile>
      <anchor>ab09a7cd3905ec1d06cf03948f12e7fa4</anchor>
      <arglist>(double power_dBm)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; double &gt;</type>
      <name>powers_dBm</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_sweep.html</anchorfile>
      <anchor>acae67b9e4602afba2d056fb6a2f01287</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>frequency_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_sweep.html</anchorfile>
      <anchor>a91acfcdb00405d0e48878c2bc69caa14</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setFrequency</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_sweep.html</anchorfile>
      <anchor>a970ff5fa599be106d0aa20e4ee9ca474</anchor>
      <arglist>(double frequency, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>ifBandwidth_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_sweep.html</anchorfile>
      <anchor>a669ad1da20ac86ec3e7a6b3220b785a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setIfbandwidth</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_sweep.html</anchorfile>
      <anchor>a350d457150f3219b2c880083afb2d63c</anchor>
      <arglist>(double bandwidth, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_power_sweep.html</anchorfile>
      <anchor>a1f5f2be1f565026726526f05685f8bb8</anchor>
      <arglist>(VnaPowerSweep const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaProperties</name>
    <filename>class_rsa_toolbox_1_1_vna_properties.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaProperties</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>a33aba4b5b99bc0d3abe583b87d0e4e10</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaProperties</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>aafcbcffc0432236501d898abbb31c2b2</anchor>
      <arglist>(VnaProperties &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaProperties</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>a269ad14a79432e91a95e5f7756500667</anchor>
      <arglist>(Vna *vna, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>VnaModel</type>
      <name>model</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>a9fc082dc3c35ad05adede38a7b8bc95a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>serialNumber</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>a0256d808e3a0049a3bd80282c9823351</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>firmwareVersion</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>ace57bbc4eff73ff060fb917be8b6e40e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QStringList</type>
      <name>optionsList</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>a72f467a4b9e4a75841461dd920590758</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isZvaFamily</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>afb37f215f914593090fecc0dce5f1185</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotZvaFamily</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>a4492ee9f70995b12b2a1a16b924739f2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isZnbFamily</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>ad77069b02ebda60dce1d4a8b9b208aac</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotZnbFamily</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>a9a483f6cb88b17bfcd4825b75cd86a7c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isKnownModel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>a893989c7f65bb672bcb22c6cb466dbc7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isUnknownModel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>a5bf4c85c4a230b824a2bcca42d627f57</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>physicalPorts</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>a2f34d2683e7b1ef3bac506f4d741bc81</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>minimumFrequency_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>ae57b14f809d1115326eb2b225d0cf410</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>maximumFrequency_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>af8d4193c1724e8f3c954f807acaf138e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; double &gt;</type>
      <name>ifBandwidthMantissa_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>a410eee6d83ab0f8110f631254b34aa42</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; double &gt;</type>
      <name>ifBandwidthMantissa_KHz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>a8fdc2d59b6954a68d5993272932bae7d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; double &gt;</type>
      <name>ifBandwidthMantissa_MHz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>a2d80f7d2f215b44daa3479ab6e68bc8f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>minimumPower_dBm</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>acd4861e70e0850a4bf482c7a0f0fb9a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>maximumPower_dBm</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>ad0e788e8573b52211118295a83b06be4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>hasSourceAttenuators</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>a39ab55935b3c6166146f21aa8af74698</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; uint &gt;</type>
      <name>sourceAttenuations_dB</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>aef0f6312caf519abd12447ba75a10594</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>hasReceiverAttenuators</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>aeeba01fcad674b92b25f5f325deb480d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; uint &gt;</type>
      <name>receiverAttenuations_dB</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>a1fd63575b01163a8b4f794cfe4d4c46e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>maximumPoints</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>a7e1a7c4a1222d0813e28a5b9a0eaa85f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_properties.html</anchorfile>
      <anchor>aae55792bb41fa712e646031dad560941</anchor>
      <arglist>(VnaProperties const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaReferenceMarker</name>
    <filename>class_rsa_toolbox_1_1_vna_reference_marker.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaReferenceMarker</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_reference_marker.html</anchorfile>
      <anchor>acd62a9b6a0974701894cca5940ba1372</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaReferenceMarker</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_reference_marker.html</anchorfile>
      <anchor>a99e580ef72992484fbf0998f81381e84</anchor>
      <arglist>(const VnaReferenceMarker &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaReferenceMarker</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_reference_marker.html</anchorfile>
      <anchor>a5261ca8a942734998b7264ad42c9ba31</anchor>
      <arglist>(Vna *vna, VnaTrace *trace, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaReferenceMarker</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_reference_marker.html</anchorfile>
      <anchor>a1eb15b20ead77b96d580c72e974f8c0f</anchor>
      <arglist>(Vna *vna, QString traceName, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_reference_marker.html</anchorfile>
      <anchor>a3909f77aa50b8f46ccadc196178a07a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>on</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_reference_marker.html</anchorfile>
      <anchor>af5ab223c4aa62b4fc1bcc3a166bc2517</anchor>
      <arglist>(bool isOn=true)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_reference_marker.html</anchorfile>
      <anchor>a45cb35cce9c006e0f1428934f6d828cb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>off</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_reference_marker.html</anchorfile>
      <anchor>a785abb1dda82d2aa86dca3b47ad8c5db</anchor>
      <arglist>(bool isOff=true)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>name</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_reference_marker.html</anchorfile>
      <anchor>aee2dd8a62805e14b9f0b407a27159117</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setName</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_reference_marker.html</anchorfile>
      <anchor>a6220fae15759fd0fa7d75e415df34e83</anchor>
      <arglist>(QString name)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>x</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_reference_marker.html</anchorfile>
      <anchor>a1d181ea8ec179ff8046ef6cf2a8aa232</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>y</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_reference_marker.html</anchorfile>
      <anchor>a52c7eae49e9d0d75c6cc38f61ed526f2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>coordinates</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_reference_marker.html</anchorfile>
      <anchor>ada220dcb18bad3f30ae11714ff06c405</anchor>
      <arglist>(double &amp;x, double &amp;y)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setX</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_reference_marker.html</anchorfile>
      <anchor>aebaa65e5092d73ad02999226a63bb126</anchor>
      <arglist>(double x, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setToMarker</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_reference_marker.html</anchorfile>
      <anchor>a3a6cfc6f47fe304a1fd3f13087bc472a</anchor>
      <arglist>(uint markerIndex)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_reference_marker.html</anchorfile>
      <anchor>a64c5b63227cdd72bf355ef881893dab1</anchor>
      <arglist>(VnaReferenceMarker const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaSegmentedSweep</name>
    <filename>class_rsa_toolbox_1_1_vna_segmented_sweep.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaSegmentedSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>ac33d7c2c57918982b7e1bbb7aff6c22f</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaSegmentedSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>a2d6fcf25a3c209be8e503d92fa4a97bc</anchor>
      <arglist>(VnaSegmentedSweep &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaSegmentedSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>a294ed65a7f9060bcd12c946a6121d80a</anchor>
      <arglist>(Vna *vna, VnaChannel *channel, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaSegmentedSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>aac07f10b686506d024f8daede103a685</anchor>
      <arglist>(Vna *vna, uint channelIndex, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>points</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>acbdc0bd270e1acb2eee1f8c9a7f9a85d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>start_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>a413388b196a6bcd75bb8ee9284d56af4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>stop_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>a52c971759a84fc28fa0735ce04b3e1fc</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; double &gt;</type>
      <name>frequencies_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>aaf0a017e8ef1baa58e87488e548de3b3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>power_dBm</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>aed9bf0f8af990a0e5169bcbd4c6fda0e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPower</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>aac822adb781e223a96898409db296a43</anchor>
      <arglist>(double power_dBm)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>ifBandwidth_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>a669ad1da20ac86ec3e7a6b3220b785a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setIfbandwidth</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>a350d457150f3219b2c880083afb2d63c</anchor>
      <arglist>(double bandwidth, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>segments</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>a1a153e038ad1b8671cc2827ead10e087</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>addSegment</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>ac6bb8a49fbffc26fcb5588dcf0782ccb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeSegment</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>a9caa4c5a15a09fdcd84e62ffb78234f3</anchor>
      <arglist>(uint index)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeSegments</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>a3ecd83ff27ba319307525fa4fcf7c7ef</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaSweepSegment &amp;</type>
      <name>segment</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>a2bedd7d605d2c6bc7f46088a5a850838</anchor>
      <arglist>(uint index)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; uint &gt;</type>
      <name>sParameterGroup</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>ac7a50334398a7820485919ddb24150dd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setSParameterGroup</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>ae03d74323281e5fac2ac8c60272add1c</anchor>
      <arglist>(QVector&lt; uint &gt; ports)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>clearSParameterGroup</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>af0435978efe0339d462c159ca1b00864</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>ComplexMatrix3D</type>
      <name>readSParameterGroup</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>a83cd1058a5091918d294e1ba612941ae</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>NetworkData</type>
      <name>measure</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>a1139e1760db35d5c1304e8072b289f10</anchor>
      <arglist>(uint port1)</arglist>
    </member>
    <member kind="function">
      <type>NetworkData</type>
      <name>measure</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>a108ba0072a55a62c6d70cfe0aa361b9f</anchor>
      <arglist>(uint port1, uint port2)</arglist>
    </member>
    <member kind="function">
      <type>NetworkData</type>
      <name>measure</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>a269807991452399fc4607e261d60318e</anchor>
      <arglist>(uint port1, uint port2, uint port3)</arglist>
    </member>
    <member kind="function">
      <type>NetworkData</type>
      <name>measure</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>ad99b8de57e97aa43fe5d0d36967389e7</anchor>
      <arglist>(uint port1, uint port2, uint port3, uint port4)</arglist>
    </member>
    <member kind="function">
      <type>NetworkData</type>
      <name>measure</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>a0adcf6cc4450039b97795779197b9792</anchor>
      <arglist>(QVector&lt; uint &gt; ports)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_segmented_sweep.html</anchorfile>
      <anchor>a1de61dd353557f367470fda30dc1c52e</anchor>
      <arglist>(VnaSegmentedSweep const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaSettings</name>
    <filename>class_rsa_toolbox_1_1_vna_settings.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaSettings</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>addf94e0241e4e5344797b8b81c82529c</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaSettings</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a4e9edb51c6769b1e0b6069ab693bce74</anchor>
      <arglist>(VnaSettings &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaSettings</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a42d202abc6c14f20cfa456107464840e</anchor>
      <arglist>(Vna *_vna, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setIdString</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>aa0a04d1ffe960e8a302df345a4de584f</anchor>
      <arglist>(QString idString)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>resetIdString</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>aa522a8d7f118450ee28b9c910a759901</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setOptionsString</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a58c6dcf61c76c4894217f5586a8b1e91</anchor>
      <arglist>(QString options)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>resetOptionsString</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a1a5b949763bfdf2c9944fe3fc145343a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isRead32BitBinaryFormat</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a9969043ea62cb34360d572aecbf933e0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isRead64BitBinaryFormat</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a02af076efb3f0fb58a28d18d2657b8d6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isReadAsciiFormat</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a5771354d41b36bb144928896b7ca9411</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isLittleEndian</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a80481a1d1a192de35c3bdd6e8cd0480b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isBigEndian</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a7dc61b9dbc3b51e0641eeb7b56067e4c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setRead32BitBinaryFormat</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>ae7291a1623ec7c75171fcf91d448f5da</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setRead64BitBinaryFormat</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a52d069abf12dd5b1440c18f9187fa5d0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setReadAsciiFormat</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a6041bd69ba2a13714924c226fcc88c4b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setLittleEndian</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a23e35dfdf01b8c7c81e9b84163d2d8ec</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setBigEndian</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a8ca2a45b5644d3a060297019d9a16458</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isEmulationOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>abc064602ce85baabf932e9681d078077</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isEmulationOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a6b3386696e18f2c993355a63f71e30fa</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isEmulationMode</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>ae39c3edb69bae81137c0d66b69339f01</anchor>
      <arglist>(VnaEmulationMode mode)</arglist>
    </member>
    <member kind="function">
      <type>VnaEmulationMode</type>
      <name>emulationMode</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a2538776253c2692c4479e3907cb9f120</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setEmulationMode</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a6211fa0d70a641a9b255005884e27a07</anchor>
      <arglist>(VnaEmulationMode mode)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setEmulationOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>af14210134cec8dae8bb930aa9941d5da</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isDisplayOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>aacb29a9af2b4219294fbc50061aeb1c4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isDisplayOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>aded0d394acbb2b40cbb96f9037db4715</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>displayOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a0b728064fd1bdec9d4ff40e9fd1270ce</anchor>
      <arglist>(bool isOn=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>displayOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a114ee767aaa7fe3b1801930f5501f216</anchor>
      <arglist>(bool isOff=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>manualDisplayMode</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a47cb7fcf6d0dcd15970d4635d2e37681</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>updateDisplay</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>ab7eb3c8c2e8604801ee00f11d3af8c3f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isErrorDisplayOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a195f45d131d367c4a4d25c7208d5b79e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isErrorDisplayOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>af7aa049e40a28412ca1f92b58fd6353a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>errorDisplayOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>ac31faa95e87825097a07a3545557e41b</anchor>
      <arglist>(bool isOn=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>errorDisplayOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a71a26e3f5a93085e8bf4433367c69f2c</anchor>
      <arglist>(bool isOff=true)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isColorScheme</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>ab8e7fd30ad03193c7794607102873aa7</anchor>
      <arglist>(VnaColorScheme scheme)</arglist>
    </member>
    <member kind="function">
      <type>VnaColorScheme</type>
      <name>colorScheme</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a8577f6c5832e93bbdafca54bbc4e8d81</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setColorScheme</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>aa4f78c4ed886f85589847d365c90035c</anchor>
      <arglist>(VnaColorScheme scheme)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDefaultColorScheme</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>acb19953e68978b764e1e734afceedde0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isFontSize</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a5ad0f68c09a4290e50fc1ecce34a2bf5</anchor>
      <arglist>(uint size_percent)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>fontSize_percent</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a995a8420d3eae318e0cc39adac721577</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setFontSize</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a7a4af07b25f5bc2e8270063972e25b50</anchor>
      <arglist>(uint size_percent)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>resetFontSize</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a72300b94eb5cdeb58d0091ef6733e975</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isUserPresetOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>add40256e9b69054f552f1cc35cbeb066</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isUserPresetOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>abe1984e452b68fca7d7f9650f5d4451d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>userPresetOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>aece6964c8f5a619422f79e3dcfa450af</anchor>
      <arglist>(bool isOn=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>userPresetOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a8256d6b16604459d63e7e3fd84686a6e</anchor>
      <arglist>(bool isOff=true)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>userPreset</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>aa936e5d9cdc1289d325e8ae242a82b33</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setUserPreset</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a6fe32306115d59ed0dcff0ea0bc2cc89</anchor>
      <arglist>(QString setFilePath)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isUserPresetMappedToRst</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a52b64409a650f3ee42860fbe7e4529ee</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>mapUserPresetToRst</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>ac84143c56ba9e5462d14005ad21e12ea</anchor>
      <arglist>(bool isMapped)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isCalibrationPresetOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a749a1b0771f5eb8cff1b96f128c7c56b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isCalibrationPresetOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a4079cbc1abb10c8e2dc6514e0f1250a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>calibrationPresetOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a596001181fc46399ce7d7ff1b8f79249</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>calibrationPreset</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>ad495e678cfec341c363b434fd3a201c1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCalibrationPreset</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a05ac48e14488beb65f8cc45064f7a3da</anchor>
      <arglist>(QString calibrationFilePath)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isPortPowerLimitOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a4c142a2234b8706792c4db19b4943067</anchor>
      <arglist>(uint physicalPort)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isPortPowerLimitOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>ac01a5b90a98b968bcb24952eb95bd6e4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isPortPowerLimitOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a19e4f8ab93012daca55b9bae6430c678</anchor>
      <arglist>(uint physicalPort)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isPortPowerLimitOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a367abd8ac1457d8de78e31f300b63750</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>portPowerLimitOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a9e25a89c12bd3929decb8b0bb20bfd4f</anchor>
      <arglist>(uint physicalPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>portPowerLimitsOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a897f6ec88b35f17579d5fd7b1ff87d50</anchor>
      <arglist>(bool isOn=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>portPowerLimitOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a1d65cd48864451d0c5125a09f5de7785</anchor>
      <arglist>(uint physicalPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>portPowerLimitsOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a62bd3cbe05b30630b7163b18102fa532</anchor>
      <arglist>(bool isOff=true)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>portPowerLimit_dBm</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a3564eb13fae18cc13fbcc88b57bf5386</anchor>
      <arglist>(uint physicalPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>portPowerLimits</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a25cc79eb65a19646e21f6c9eb34c6482</anchor>
      <arglist>(QVector&lt; uint &gt; &amp;physicalPorts, QVector&lt; double &gt; limits_dBm)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPortPowerLimit</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a24af467a6d0c39263ed3218f92dbc11a</anchor>
      <arglist>(uint physicalPort, double limit_dBm)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPortPowerLimits</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>ae3b34daf6ff4fd960516297a9d68aba8</anchor>
      <arglist>(double limit_dBm)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isRfOutputPowerOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a29b22106f6b7f227706d7624c6a33094</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isRfOutputPowerOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a5c7189fe424f93152ec1ab90a022622a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>rfOutputPowerOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a56828aebc092996152ac86aa61e449a6</anchor>
      <arglist>(bool isOn=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>rfOutputPowerOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>ab6155ac7677ab19a1eeef1feb392f38a</anchor>
      <arglist>(bool isOff=true)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isDynamicIfBandwidthOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>ab031657070139cfd48714e5f28e3e5ed</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isDynamicIfBandwidthOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>abe8bfe93cf6a3073043c77c4164569d7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>dynamicIfBandwidthOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a44d2e1c48ca2e713a3e79118b816ff79</anchor>
      <arglist>(bool isOn=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>dynamicIfBandwidthOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>aeb235541215bdf0692d2a114668ec75e</anchor>
      <arglist>(bool isOff=true)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isLowPowerAutoCalOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>aa756f14c5e449bd9eafa85fad2ee777c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isLowPowerAutoCalOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>ac52b2dbbfbd2e2df24f77fd243debb51</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>lowPowerAutoCalOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a639313bc68326a23e18fa346f7678ce8</anchor>
      <arglist>(bool isOn=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>lowPowerAutoCalOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a39734464e7352e1d6f65c418f7cda056</anchor>
      <arglist>(bool isOff=true)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isRemoteLogOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a60f1ac649ceed666865ef2027b8254c6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isRemoteLogOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a8a5130fef789a4b1c8cd11097e8a269f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>remoteLogOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a2683c0e9d762bbe519fef0512608603e</anchor>
      <arglist>(bool isOn=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>remoteLogOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a40b319d5a7b18048b60a17025e031a26</anchor>
      <arglist>(bool isOff=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_settings.html</anchorfile>
      <anchor>a06223e072386ef58b3c655636a7a953b</anchor>
      <arglist>(VnaSettings const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaStandardModel</name>
    <filename>class_rsa_toolbox_1_1_vna_standard_model.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaStandardModel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_standard_model.html</anchorfile>
      <anchor>a946b62a0b5798f86c044e56564fd6cee</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_standard_model.html</anchorfile>
      <anchor>a856131836f36d54654ae68b11f194031</anchor>
      <arglist>(VnaStandardModel const &amp;other)</arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>eLength_m</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_standard_model.html</anchorfile>
      <anchor>a1e5940993d95a72e1b173f96c6de6a8d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>loss_dB_per_sqrt_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_standard_model.html</anchorfile>
      <anchor>a205881708c5ab84c2704bd526724dc7e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>Z0_Ohms</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_standard_model.html</anchorfile>
      <anchor>a97f4126e4a6236d18485fd895755a649</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>C0_fF</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_standard_model.html</anchorfile>
      <anchor>a86634aa9ef917c1d39a2bc5c9fb67731</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>C1_fF_per_GHz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_standard_model.html</anchorfile>
      <anchor>abcda172b984cf09db100acac626cbee7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>C2_fF_per_GHz2</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_standard_model.html</anchorfile>
      <anchor>a8f7f72307075e000496a26a994957399</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>C3_fF_per_GHz3</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_standard_model.html</anchorfile>
      <anchor>a42f17f426e772cc710d60b2a3ab4eeec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>L0_pH</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_standard_model.html</anchorfile>
      <anchor>a92187b1e03210d3e62b9308b4dca93fc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>L1_pH_per_GHz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_standard_model.html</anchorfile>
      <anchor>a4d4c4eabe39453d652deb797f19b645a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>L2_pH_per_GHz2</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_standard_model.html</anchorfile>
      <anchor>aa941f11de5c07212b6b6b598a797a7ca</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>L3_pH_per_GHz3</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_standard_model.html</anchorfile>
      <anchor>af81276ab7649a72ebb05ea59d3cf7773</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>R_Ohms</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_standard_model.html</anchorfile>
      <anchor>a085f836b740baf29d750dd67fca6c749</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaSweepSegment</name>
    <filename>class_rsa_toolbox_1_1_vna_sweep_segment.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaSweepSegment</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_sweep_segment.html</anchorfile>
      <anchor>a8398de1678562a61d4a50fc816966c17</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaSweepSegment</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_sweep_segment.html</anchorfile>
      <anchor>a26989077aa3714a1ceb52406c0fd71ef</anchor>
      <arglist>(VnaSweepSegment &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaSweepSegment</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_sweep_segment.html</anchorfile>
      <anchor>ad73700e5adbc02b67ca0627de75877e2</anchor>
      <arglist>(Vna *vna, VnaChannel *channel, uint index, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaSweepSegment</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_sweep_segment.html</anchorfile>
      <anchor>a5a182a7d9f661dd1064a10df9bda3840</anchor>
      <arglist>(Vna *vna, uint channelIndex, uint segmentIndex, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_sweep_segment.html</anchorfile>
      <anchor>a3909f77aa50b8f46ccadc196178a07a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_sweep_segment.html</anchorfile>
      <anchor>a45cb35cce9c006e0f1428934f6d828cb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>on</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_sweep_segment.html</anchorfile>
      <anchor>af5a2f93105e0a24634af5793d2c5c5b8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>off</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_sweep_segment.html</anchorfile>
      <anchor>a2f241b422ebdbd7a570178ceaebdd2fa</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>points</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_sweep_segment.html</anchorfile>
      <anchor>acbdc0bd270e1acb2eee1f8c9a7f9a85d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPoints</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_sweep_segment.html</anchorfile>
      <anchor>a865b3daabe5358c3695484b9ceaf8028</anchor>
      <arglist>(uint numberOfPoints)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>start_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_sweep_segment.html</anchorfile>
      <anchor>a413388b196a6bcd75bb8ee9284d56af4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setStart</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_sweep_segment.html</anchorfile>
      <anchor>a5ac411e306b822644e9740e62329b90c</anchor>
      <arglist>(double frequency, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>stop_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_sweep_segment.html</anchorfile>
      <anchor>a52c971759a84fc28fa0735ce04b3e1fc</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setStop</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_sweep_segment.html</anchorfile>
      <anchor>a417769e36a3253632c77c5ee09a89698</anchor>
      <arglist>(double frequency, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setSingleFrequency</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_sweep_segment.html</anchorfile>
      <anchor>a719c014a31197142a0623125c3748b58</anchor>
      <arglist>(double frequency, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_sweep_segment.html</anchorfile>
      <anchor>aebb57f0753b1f2301e70345a29d25271</anchor>
      <arglist>(VnaSweepSegment const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaSwitchMatrix</name>
    <filename>class_rsa_toolbox_1_1_vna_switch_matrix.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaSwitchMatrix</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_switch_matrix.html</anchorfile>
      <anchor>a896aaf667e2d3da8bfe012b8912fd9f3</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaSwitchMatrix</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_switch_matrix.html</anchorfile>
      <anchor>a19870ce3c5b473569aee09138db04069</anchor>
      <arglist>(const VnaSwitchMatrix &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaSwitchMatrix</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_switch_matrix.html</anchorfile>
      <anchor>aec91b536ba305a6951526c5e89ff4f92</anchor>
      <arglist>(Vna *vna, uint index, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_switch_matrix.html</anchorfile>
      <anchor>a06fc446f121d1dc8b59fcccc62e63cc3</anchor>
      <arglist>(VnaSwitchMatrix const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaTimeDomain</name>
    <filename>class_rsa_toolbox_1_1_vna_time_domain.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaTimeDomain</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a1239cc10fc901cbadbd9c084a1463dcc</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaTimeDomain</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a56bc0376419dc1b9ad167fd1f8a8704d</anchor>
      <arglist>(const VnaTimeDomain &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaTimeDomain</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>acc195eaa22f8f06e5dd92fc5e017bf65</anchor>
      <arglist>(Vna *vna, VnaTrace *trace, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaTimeDomain</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a957e58b99169749c88a5d671e27caca3</anchor>
      <arglist>(Vna *vna, QString traceName, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a3909f77aa50b8f46ccadc196178a07a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a45cb35cce9c006e0f1428934f6d828cb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>on</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>af5ab223c4aa62b4fc1bcc3a166bc2517</anchor>
      <arglist>(bool isOn=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>off</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a785abb1dda82d2aa86dca3b47ad8c5db</anchor>
      <arglist>(bool isOff=true)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isBandpassImpulseResponse</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a9b0838ba8570c93ba0ddcddbba2f2c48</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setBandpassImpulseResponse</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a250613ed23ea4de03dbe390543c4b4a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isLowpassImpulseResponse</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a25db06cd85fdf152df5db531c4c703b7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setLowpassImpulseResponse</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a41e66101a3e7ef6541c0927b5054eeff</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isLowpassStepResponse</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a7d8914e06fefb97ee3699d40c0b3ab49</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setLowpassStepResponse</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>ac8e746784dc3a33c53788900379127c2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isAutomaticDcExtrapolation</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>aeda280763069af9ce7833c52426828ce</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isManualDcExtrapolation</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a5d27a26fdc39e240570bed4fbe8a3f15</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>automaticDcExtrapolationOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a9c0d10405d1f019cdbf0956fbc55b157</anchor>
      <arglist>(bool isOn=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>manualDcExtrapolationOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a49b3c2dc6688aa01bf38950b3b3a8541</anchor>
      <arglist>(bool isOn=true)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>extrapolatedDcValue</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>aff5e6c457d4163871a1836defc3b821e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setExtrapolatedDcValue</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a9511649dace890640ec3f1372428bf10</anchor>
      <arglist>(double dcValue)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isResolutionEnhancementOn</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>ab6baa4d9cd6634da40c5762636823145</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isResolutionEnhancementOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a8da8b3011550bb3b33e73a864089d5a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>resolutionEnhancementFactor</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a681bbbdf615887c1f6c4166b48754956</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>resolutionEnhancementOff</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>aa1a8be867cc05760659c38d735e2762d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setResolutionEnhancement</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a3767a62aae3d37beb61813a74b70aac7</anchor>
      <arglist>(double factor)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isWindow</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a793bc2353c8997c1b4f1c94acd88caf4</anchor>
      <arglist>(VnaWindowFunction window)</arglist>
    </member>
    <member kind="function">
      <type>VnaWindowFunction</type>
      <name>window</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>ae62e6dbfef0461f8c11ae38fe84a0cb7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setWindow</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>af7fdf17cd2a097aa5ef354364295fef0</anchor>
      <arglist>(VnaWindowFunction window)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>slowestRiseTime_s</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a748a9337ef25794be7f609e834714aa7</anchor>
      <arglist>(RiseTimeDefinition definition=RISETIME_10_TO_90)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>fastestRiseTime_s</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a9ebe3086cf7b00ca034061c720cef8f5</anchor>
      <arglist>(RiseTimeDefinition definition=RISETIME_10_TO_90)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>longestRange_s</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a1bf1e0f72247a2009fd763aee3c3e156</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>longestRange_s</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a32b33df11c45c7afdde8b17b86d523d5</anchor>
      <arglist>(double riseTime_s, RiseTimeDefinition definition=RISETIME_10_TO_90)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>shortestRange_s</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a4909d0ccd58c335b28d53561c25d35d5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>shortestRange_s</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a856d397746f636768518108fdce29f0e</anchor>
      <arglist>(double riseTime_s, RiseTimeDefinition definition=RISETIME_10_TO_90)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>unambiguousRange_s</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>ad8ee56116205c0a76f32d87c86c259e1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>riseTime_s</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>abeabd22adbfb9664a109e72976bdabb0</anchor>
      <arglist>(RiseTimeDefinition definition)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setupChannel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>aab0f722ffcda6604b389bf0226f7f413</anchor>
      <arglist>(double riseTime_s, RiseTimeDefinition definition, double unambiguousRange_s)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setupTrace</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>aa9c203498c911621ecf7b96ed365fa43</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>adjustChannelFrequencySpacing</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>ac49b96fc7a3a6066bcf29d4fe6c94304</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>adjustChannelStopFrequency</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a48419f07cbbd00bc0d582674b9e75aa0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>adjustChannelPoints</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>acbf9b4d91c9830636f7fc7c5071e9acf</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isTimeAxis</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a32ffd4b21cc1812876b85310c14ff64b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isDistanceAxis</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>ae581b2775483556c3395a4178e02c738</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>startValue</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a24c126c4edfc695a2aa22048d1f2aa9e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setStart</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a5d579ac61690dd1c375988b51f84a2d9</anchor>
      <arglist>(double value, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>stopValue</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a9670d61da4612fd23221ba9206ae1925</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setStop</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a1018cbd0ef2694d0e126bf0b62df7b38</anchor>
      <arglist>(double value, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_domain.html</anchorfile>
      <anchor>a3ea85afd3ab94fd36d5669b62a3d12ac</anchor>
      <arglist>(VnaTimeDomain const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaTimeSweep</name>
    <filename>class_rsa_toolbox_1_1_vna_time_sweep.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaTimeSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_sweep.html</anchorfile>
      <anchor>a72965f6b47078863081e12e145bcdcc2</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaTimeSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_sweep.html</anchorfile>
      <anchor>a4741b332519a5909650de23562179b65</anchor>
      <arglist>(VnaTimeSweep &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaTimeSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_sweep.html</anchorfile>
      <anchor>af51bcb63ac20cfa695356493a330e8c0</anchor>
      <arglist>(Vna *vna, VnaChannel *channel, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaTimeSweep</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_sweep.html</anchorfile>
      <anchor>a75cdb0e772d5468be371a93057cb9e3e</anchor>
      <arglist>(Vna *vna, uint channelIndex, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>points</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_sweep.html</anchorfile>
      <anchor>acbdc0bd270e1acb2eee1f8c9a7f9a85d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPoints</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_sweep.html</anchorfile>
      <anchor>a865b3daabe5358c3695484b9ceaf8028</anchor>
      <arglist>(uint numberOfPoints)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>frequency_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_sweep.html</anchorfile>
      <anchor>a91acfcdb00405d0e48878c2bc69caa14</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setFrequency</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_sweep.html</anchorfile>
      <anchor>a970ff5fa599be106d0aa20e4ee9ca474</anchor>
      <arglist>(double frequency, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>power_dBm</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_sweep.html</anchorfile>
      <anchor>aed9bf0f8af990a0e5169bcbd4c6fda0e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPower</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_sweep.html</anchorfile>
      <anchor>aac822adb781e223a96898409db296a43</anchor>
      <arglist>(double power_dBm)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>ifBandwidth_Hz</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_sweep.html</anchorfile>
      <anchor>a669ad1da20ac86ec3e7a6b3220b785a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setIfBandwidth</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_sweep.html</anchorfile>
      <anchor>ae47765726943314de1d1a955e7f73f8e</anchor>
      <arglist>(double bandwidth, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>time_s</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_sweep.html</anchorfile>
      <anchor>aeb681e0043918b2cfb48181e990e8828</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setTime</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_sweep.html</anchorfile>
      <anchor>af35f0c87c8398df80b0c654cf81e7b2e</anchor>
      <arglist>(double time, SiPrefix prefix=NO_PREFIX)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_time_sweep.html</anchorfile>
      <anchor>af84a44722ca908cd8fb6f4660de83e89</anchor>
      <arglist>(VnaTimeSweep const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaTrace</name>
    <filename>class_rsa_toolbox_1_1_vna_trace.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaTrace</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a7af0ae74e3cd4ee0dd2a94e16f3e5502</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaTrace</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>ae4529f9a10b246b26d23519efaef00d4</anchor>
      <arglist>(const VnaTrace &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VnaTrace</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>aabb32f687d5e5a3bb29dbe0f4b0a31c3</anchor>
      <arglist>(Vna *vna, QString name, QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isVisible</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>aadc2f7e6c414e3e7016fb654293daa7f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isHidden</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a05c0adb47029724e308fbcb5bee6a6d5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>select</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>ae60563c7ee9cee897adaca8bd61f17ce</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>autoscale</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a42080b87976a6e7f1945e996b45d4df3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>show</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>af4cc61d7d505393c1bb8bff846fbb629</anchor>
      <arglist>(bool isVisible=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>hide</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a0c171aa01808d53671007b8fdb755770</anchor>
      <arglist>(bool isInvisible=true)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>name</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>aee2dd8a62805e14b9f0b407a27159117</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>channel</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a3731fdf8f8ad0d1bd891c30e1ed057d7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>diagram</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a0b8e42429fc063e0d499d47568076de4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDiagram</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a4f9ad0ff5ba19ef26460d5dba4648077</anchor>
      <arglist>(uint index)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNetworkParameter</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>afa8c13c8c566db0552d27d6d2111bdc0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>networkParameter</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>afc2067c8792060079b5ff013eb493ca5</anchor>
      <arglist>(NetworkParameter &amp;parameter, uint &amp;outputPort, uint &amp;inputPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>networkParameter</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a46771f61dfca1b4f0872032206589319</anchor>
      <arglist>(NetworkParameter &amp;parameter, BalancedPort &amp;outputPort, BalancedPort &amp;inputPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setNetworkParameter</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a14e60600693e7f11d4ebcf163eb158cc</anchor>
      <arglist>(NetworkParameter parameter, uint outputPort, uint inputPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setNetworkParameter</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>aa6c12b718c998c0f927941afc239040e</anchor>
      <arglist>(NetworkParameter parameter, BalancedPort outputPort, BalancedPort inputPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>measure</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a0b8f027fbd1ffe80326aed30e6578fe3</anchor>
      <arglist>(NetworkTraceData &amp;data)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isWaveQuantity</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>aa32e835f05ab010e7e7ce83da5f88b37</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>waveQuantity</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a3f1df747de9ab4db2a526892a023f833</anchor>
      <arglist>(WaveQuantity &amp;wave, uint &amp;port)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setWaveQuantity</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a880c4f16f510d66e03e19e19e65ef062</anchor>
      <arglist>(WaveQuantity wave, uint port)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isWaveRatio</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a119cfefcd1d83e16d4094a5d4d80cb2d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>waveRatio</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>ae439b6bf894653ce48496c73e2411f12</anchor>
      <arglist>(WaveQuantity &amp;numeratorWave, uint &amp;numeratorPort, WaveQuantity &amp;denominatorWave, uint &amp;denominatorPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setWaveRatio</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a3bcb82b9d92940e1f213c314f82e65ad</anchor>
      <arglist>(WaveQuantity outputWave, uint outputPort, WaveQuantity inputWave, uint inputPort)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isImpedance</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a254253dc3421d028ddf8de71a87dedee</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>impedance</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a2aa8f140ac5d72696814e485916d60c4</anchor>
      <arglist>(uint &amp;outputPort, uint &amp;inputPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>impedance</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a978b6cc0ff456732ba446382b7932f4a</anchor>
      <arglist>(BalancedPort &amp;outputPort, BalancedPort &amp;inputPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setImpedance</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>aebbf124a7156db040dac01839d06d50b</anchor>
      <arglist>(uint outputPort, uint inputPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setImpedance</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a0b91fe4abcdaee06fd9c3c274711896f</anchor>
      <arglist>(BalancedPort outputPort, BalancedPort inputPort)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isAdmittance</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a47de7946cf7eb93cc1054c7b5fd42147</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>admittance</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a53a11333b6c268ce1ee8f4dd2b393609</anchor>
      <arglist>(uint &amp;outputPort, uint &amp;inputPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>admittance</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a7e442906c31256f7439966802ad8d9ef</anchor>
      <arglist>(BalancedPort &amp;outputPort, BalancedPort &amp;inputPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setAdmittance</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a2808cae8c29578348c166f028b22c137</anchor>
      <arglist>(uint outputPort, uint inputPort)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setAdmittance</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>aea4b7c6c1702649758605ff13fa0bc90</anchor>
      <arglist>(BalancedPort outputPort, BalancedPort inputPort)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isTimeDomain</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a6d5dccaebacb523ee1e4e49412f04d0b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotTimeDomain</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a67fcff0cd956877da386a3fb89008946</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaTimeDomain &amp;</type>
      <name>timeDomain</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>abd0cff9ed663de7738c73cdc721699cf</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>TraceFormat</type>
      <name>format</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a6d1a2509be330df13147835c35537e24</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setFormat</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>ac5144ae6054255ee831ceee2e90bb676</anchor>
      <arglist>(TraceFormat format)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDisplayProperties</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>af564c345a4be4daca4c75ec3bcc79d73</anchor>
      <arglist>(int red, int green, int blue, Qt::PenStyle style=Qt::SolidLine, int width=1)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDisplayProperties</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a4cfba320aefd33ce1beb8a55177ba7e1</anchor>
      <arglist>(QColor color, Qt::PenStyle style=Qt::SolidLine, int width=1)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDisplayProperties</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a6ce0b30c362e0e052e77429819dc854d</anchor>
      <arglist>(QPen pen)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setYAxisMinimum</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a05a1cf83908ac03f85667ae3ea8d1dd8</anchor>
      <arglist>(double min)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setYAxisMaximum</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a13fab992a1eb6af96c2a9da22d232624</anchor>
      <arglist>(double max)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setYAxis</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>aa700883fb370926a7696daf8339927c9</anchor>
      <arglist>(double min, double max)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>points</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>acbdc0bd270e1acb2eee1f8c9a7f9a85d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QRowVector</type>
      <name>x</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a72cb2736f6dcdb7ca9ce5eabf80b575e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>y</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a690cb442f99d475441b8308fa0340178</anchor>
      <arglist>(QRowVector &amp;y)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>y</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a79441c4611a190446ac2808cec394a31</anchor>
      <arglist>(ComplexRowVector &amp;y)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>toMemory</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a494e7ea7e94a9bc939dc49c0f5fd1a75</anchor>
      <arglist>(QString name)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>write</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>ae241b1929b6396f557d3f6cca899556f</anchor>
      <arglist>(QRowVector data)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isMarker</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>ad7b7b982e6f76ed9902d50bc83f9c71c</anchor>
      <arglist>(uint index)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotMarker</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a58e9b1b296f9667d3e4f4feb15408749</anchor>
      <arglist>(uint index)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isMarkers</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>ad90a4ca1add6f0d065666bfbac5193f9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNotMarkers</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a379c594fada5c33955cafd593e829999</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; uint &gt;</type>
      <name>markers</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a33c8d621e1a9aa270ce01b635e788172</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>createMarker</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a61a40e417c96be4c9dd78b365ccd4529</anchor>
      <arglist>(uint index)</arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>createMarker</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a837fdcca12402cd4b805ce4b9d85940c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteMarker</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>aa434bd751c1746261ad26358c9aa5319</anchor>
      <arglist>(uint index)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteMarkers</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a40dec4db243091a9826180e914f2708c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VnaMarker &amp;</type>
      <name>marker</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>ad1096801748608ba10ae43d2991f253b</anchor>
      <arglist>(uint index)</arglist>
    </member>
    <member kind="function">
      <type>VnaReferenceMarker &amp;</type>
      <name>referenceMarker</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>a855640d91df16946c44dc8947de1048d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_trace.html</anchorfile>
      <anchor>ad35ccc78eaee07b5f5762ecb7094684b</anchor>
      <arglist>(VnaTrace const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RsaToolbox::VnaUserDefinedPort</name>
    <filename>class_rsa_toolbox_1_1_vna_user_defined_port.html</filename>
    <member kind="function">
      <type></type>
      <name>VnaUserDefinedPort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_user_defined_port.html</anchorfile>
      <anchor>a17dd613dba5a7e978c146a5d524e7c71</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isSource</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_user_defined_port.html</anchorfile>
      <anchor>afa932ff571342376632e1c7f4b550012</anchor>
      <arglist>(uint port) const </arglist>
    </member>
    <member kind="function">
      <type>uint</type>
      <name>sourcePort</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_user_defined_port.html</anchorfile>
      <anchor>a66b4f22690650de1a5515262ba7aadb6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setSource</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_user_defined_port.html</anchorfile>
      <anchor>aadf6be860f75ef7a66ea1ce57019a45e</anchor>
      <arglist>(uint port)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isReference</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_user_defined_port.html</anchorfile>
      <anchor>ad870fdb4ef23cbc0e98512aff1288e20</anchor>
      <arglist>(uint port, VnaReceiver receiver) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>reference</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_user_defined_port.html</anchorfile>
      <anchor>a2e750cc3eb388ba92e403f11ad9bfc5b</anchor>
      <arglist>(uint &amp;port, VnaReceiver &amp;receiver) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setReference</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_user_defined_port.html</anchorfile>
      <anchor>abd418c324fe9848925ee1aca83bf082f</anchor>
      <arglist>(uint port, VnaReceiver receiver)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isMeasure</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_user_defined_port.html</anchorfile>
      <anchor>a515728d58508fdba2e64fae03b95ad63</anchor>
      <arglist>(uint port, VnaReceiver receiver) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>measure</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_user_defined_port.html</anchorfile>
      <anchor>a07e465653e698b92a9de11d4b49d3124</anchor>
      <arglist>(uint &amp;port, VnaReceiver &amp;receiver) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setMeasure</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_user_defined_port.html</anchorfile>
      <anchor>a8bb22d858c307df950af6e5233e01944</anchor>
      <arglist>(uint port, VnaReceiver receiver)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>class_rsa_toolbox_1_1_vna_user_defined_port.html</anchorfile>
      <anchor>adf0669f39b18585724caa794a289af5e</anchor>
      <arglist>(VnaUserDefinedPort const &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="dir">
    <name>Bus</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Bus/</path>
    <filename>dir_aea23620b9d20c80320ef66f596f33e0.html</filename>
    <dir>Bus/Rsib</dir>
    <dir>Bus/Visa</dir>
    <file>GenericBus.cpp</file>
    <file>GenericBus.h</file>
  </compound>
  <compound kind="dir">
    <name>General</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/General/</path>
    <filename>dir_31c2500c25d0b570f9d116670e5783cb.html</filename>
    <file>BalancedPort.cpp</file>
    <file>BalancedPort.h</file>
    <file>Connector.cpp</file>
    <file>Connector.h</file>
    <file>Definitions.h</file>
    <file>General.cpp</file>
    <file>General.h</file>
    <file>IndexName.cpp</file>
    <file>IndexName.h</file>
    <file>Key.h</file>
    <file>NameLabel.cpp</file>
    <file>NameLabel.h</file>
    <file>NetworkData.cpp</file>
    <file>NetworkData.h</file>
    <file>NetworkTraceData.cpp</file>
    <file>NetworkTraceData.h</file>
    <file>SnpStreamReader.cpp</file>
    <file>SnpStreamReader.h</file>
    <file>SnpStreamWriter.cpp</file>
    <file>SnpStreamWriter.h</file>
    <file>Touchstone.cpp</file>
    <file>Touchstone.h</file>
  </compound>
  <compound kind="dir">
    <name>Instruments</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/</path>
    <filename>dir_b32872ef41c5ac3dcd463f1fa6a32513.html</filename>
    <dir>Instruments/Rsc</dir>
    <dir>Instruments/Vna</dir>
    <file>GenericInstrument.cpp</file>
    <file>GenericInstrument.h</file>
  </compound>
  <compound kind="dir">
    <name>Log</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Log/</path>
    <filename>dir_fc30d8bc4c52f877dd2b6315e410f6d2.html</filename>
    <file>Log.cpp</file>
    <file>Log.h</file>
  </compound>
  <compound kind="dir">
    <name>Instruments/Rsc</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Rsc/</path>
    <filename>dir_81bb15bf896ff429785f2524149495ff.html</filename>
    <file>Rsc.cpp</file>
    <file>Rsc.h</file>
  </compound>
  <compound kind="dir">
    <name>Bus/Rsib</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Bus/Rsib/</path>
    <filename>dir_096b222f2851736a2c7c8e1c1909a626.html</filename>
    <file>rsib.h</file>
    <file>RsibBus.cpp</file>
    <file>RsibBus.h</file>
  </compound>
  <compound kind="dir">
    <name>Bus/Visa</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Bus/Visa/</path>
    <filename>dir_70dccc6aef809ebed168616235c1cbec.html</filename>
    <file>visa.h</file>
    <file>VisaBus.cpp</file>
    <file>VisaBus.h</file>
    <file>visatype.h</file>
  </compound>
  <compound kind="dir">
    <name>Instruments/Vna</name>
    <path>C:/Users/lalic/Documents/Qt/RsaToolbox/Instruments/Vna/</path>
    <filename>dir_a17bacab68dc142356e39a91cc299c32.html</filename>
    <file>Vna.cpp</file>
    <file>Vna.h</file>
    <file>VnaAveraging.cpp</file>
    <file>VnaAveraging.h</file>
    <file>VnaCalibrate.cpp</file>
    <file>VnaCalibrate.h</file>
    <file>VnaCalKit.cpp</file>
    <file>VnaCalKit.h</file>
    <file>VnaCalStandard.cpp</file>
    <file>VnaCalStandard.h</file>
    <file>VnaCalUnit.cpp</file>
    <file>VnaCalUnit.h</file>
    <file>VnaChannel.cpp</file>
    <file>VnaChannel.h</file>
    <file>VnaCorrections.cpp</file>
    <file>VnaCorrections.h</file>
    <file>VnaCwSweep.cpp</file>
    <file>VnaCwSweep.h</file>
    <file>VnaDiagram.cpp</file>
    <file>VnaDiagram.h</file>
    <file>VnaFileSystem.cpp</file>
    <file>VnaFileSystem.h</file>
    <file>VnaLinearSweep.cpp</file>
    <file>VnaLinearSweep.h</file>
    <file>VnaLogSweep.cpp</file>
    <file>VnaLogSweep.h</file>
    <file>VnaMarker.cpp</file>
    <file>VnaMarker.h</file>
    <file>VnaPowerCalibrate.cpp</file>
    <file>VnaPowerCalibrate.h</file>
    <file>VnaPowerCorrections.cpp</file>
    <file>VnaPowerCorrections.h</file>
    <file>VnaPowerSweep.cpp</file>
    <file>VnaPowerSweep.h</file>
    <file>VnaProperties.cpp</file>
    <file>VnaProperties.h</file>
    <file>VnaReferenceMarker.cpp</file>
    <file>VnaReferenceMarker.h</file>
    <file>VnaSegmentedSweep.cpp</file>
    <file>VnaSegmentedSweep.h</file>
    <file>VnaSettings.cpp</file>
    <file>VnaSettings.h</file>
    <file>VnaStandardModel.cpp</file>
    <file>VnaStandardModel.h</file>
    <file>VnaSweepSegment.cpp</file>
    <file>VnaSweepSegment.h</file>
    <file>VnaSwitchMatrix.cpp</file>
    <file>VnaSwitchMatrix.h</file>
    <file>VnaTimeDomain.cpp</file>
    <file>VnaTimeDomain.h</file>
    <file>VnaTimeSweep.cpp</file>
    <file>VnaTimeSweep.h</file>
    <file>VnaTrace.cpp</file>
    <file>VnaTrace.h</file>
    <file>VnaUserDefinedPort.cpp</file>
    <file>VnaUserDefinedPort.h</file>
  </compound>
  <compound kind="page">
    <name>index</name>
    <title>RsaToolbox Welcome to RsaToolbox!</title>
    <filename>index</filename>
  </compound>
</tagfile>
