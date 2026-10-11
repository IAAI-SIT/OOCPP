# Compile Check

- P13_01_StreamBasics: PASS
- P13_02_BufferFlush: PASS
- P13_03_FormatOutput: PASS
- P13_04_CinWhitespace: PASS
- P13_05_CinGetlineTrap: PASS
- P13_06_InputStateRecovery: PASS
- P13_07_CharGetPut: PASS
- P13_08_FileOpenModes: PASS
- P13_09_TextWriteRead: PASS
- P13_10_TextUppercase: PASS
- P13_11_TextReadRobust: PASS
- P13_12_BinaryArray: PASS
- P13_13_BinaryRecordFormat: PASS
  /mnt/data/OOP_Chapter13_IO_Streams/P13_13_BinaryRecordFormat/main.cpp: In function ‘int main()’:
/mnt/data/OOP_Chapter13_IO_Streams/P13_13_BinaryRecordFormat/main.cpp:19:5: warning: this ‘for’ clause does not guard... [-Wmisleading-indentation]
   19 |     for(int i=0;i<count;++i) if(!writeRecord(out,a[i])){cerr<<"write error"<<endl;return 1;} out.close();
      |     ^~~
/mnt/data/OOP_Chapter13_IO_Streams/P13_13_BinaryRecordFormat/main.cpp:19:94: note: ...this statement, but the latter is misleadingly indented as if it were guarded by the ‘for’
   19 |     for(int i=0;i<count;++i) if(!writeRecord(out,a[i])){cerr<<"write error"<<endl;return 1;} out.close();
      |                                                                                              ^~~
- P13_14_StringstreamBuildParse: PASS
- P13_15_StringstreamValidate: PASS
- P13_16_AI_CinGetlineReview: PASS
- P13_17_AI_WhileEofReview: PASS
- P13_18_IntegratedDemo: PASS