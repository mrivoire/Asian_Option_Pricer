##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=PricerOptions_LastVersion
ConfigurationName      :=Debug
WorkspacePath          :="C:/Users/HP/OneDrive - De Vinci/Documents/Cours/ESILV 4A IF/MyWorkspace"
ProjectPath            :="C:/Users/HP/OneDrive - De Vinci/Documents/Cours/ESILV 4A IF/MyWorkspace/PricerOptions_LastVersion"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=HP
Date                   :=22/12/2018
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="PricerOptions_LastVersion.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall -std=c++11 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall -std=c++11 $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/EuropeanPriceAssessment.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/AbstractOption.cpp$(ObjectSuffix) $(IntermediateDirectory)/DigitalOption.cpp$(ObjectSuffix) $(IntermediateDirectory)/BinLatticeNode.cpp$(ObjectSuffix) $(IntermediateDirectory)/ConsoleColor.cpp$(ObjectSuffix) $(IntermediateDirectory)/AsianOption.cpp$(ObjectSuffix) $(IntermediateDirectory)/EuropeanOption.cpp$(ObjectSuffix) $(IntermediateDirectory)/BlackScholes.cpp$(ObjectSuffix) $(IntermediateDirectory)/CRR.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/AmericanOption.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/EuropeanPriceAssessment.cpp$(ObjectSuffix): EuropeanPriceAssessment.cpp $(IntermediateDirectory)/EuropeanPriceAssessment.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/HP/OneDrive - De Vinci/Documents/Cours/ESILV 4A IF/MyWorkspace/PricerOptions_LastVersion/EuropeanPriceAssessment.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EuropeanPriceAssessment.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EuropeanPriceAssessment.cpp$(DependSuffix): EuropeanPriceAssessment.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EuropeanPriceAssessment.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EuropeanPriceAssessment.cpp$(DependSuffix) -MM EuropeanPriceAssessment.cpp

$(IntermediateDirectory)/EuropeanPriceAssessment.cpp$(PreprocessSuffix): EuropeanPriceAssessment.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EuropeanPriceAssessment.cpp$(PreprocessSuffix) EuropeanPriceAssessment.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/HP/OneDrive - De Vinci/Documents/Cours/ESILV 4A IF/MyWorkspace/PricerOptions_LastVersion/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/AbstractOption.cpp$(ObjectSuffix): AbstractOption.cpp $(IntermediateDirectory)/AbstractOption.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/HP/OneDrive - De Vinci/Documents/Cours/ESILV 4A IF/MyWorkspace/PricerOptions_LastVersion/AbstractOption.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/AbstractOption.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/AbstractOption.cpp$(DependSuffix): AbstractOption.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/AbstractOption.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/AbstractOption.cpp$(DependSuffix) -MM AbstractOption.cpp

$(IntermediateDirectory)/AbstractOption.cpp$(PreprocessSuffix): AbstractOption.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/AbstractOption.cpp$(PreprocessSuffix) AbstractOption.cpp

$(IntermediateDirectory)/DigitalOption.cpp$(ObjectSuffix): DigitalOption.cpp $(IntermediateDirectory)/DigitalOption.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/HP/OneDrive - De Vinci/Documents/Cours/ESILV 4A IF/MyWorkspace/PricerOptions_LastVersion/DigitalOption.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DigitalOption.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DigitalOption.cpp$(DependSuffix): DigitalOption.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DigitalOption.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DigitalOption.cpp$(DependSuffix) -MM DigitalOption.cpp

$(IntermediateDirectory)/DigitalOption.cpp$(PreprocessSuffix): DigitalOption.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DigitalOption.cpp$(PreprocessSuffix) DigitalOption.cpp

$(IntermediateDirectory)/BinLatticeNode.cpp$(ObjectSuffix): BinLatticeNode.cpp $(IntermediateDirectory)/BinLatticeNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/HP/OneDrive - De Vinci/Documents/Cours/ESILV 4A IF/MyWorkspace/PricerOptions_LastVersion/BinLatticeNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BinLatticeNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BinLatticeNode.cpp$(DependSuffix): BinLatticeNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BinLatticeNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BinLatticeNode.cpp$(DependSuffix) -MM BinLatticeNode.cpp

$(IntermediateDirectory)/BinLatticeNode.cpp$(PreprocessSuffix): BinLatticeNode.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BinLatticeNode.cpp$(PreprocessSuffix) BinLatticeNode.cpp

$(IntermediateDirectory)/ConsoleColor.cpp$(ObjectSuffix): ConsoleColor.cpp $(IntermediateDirectory)/ConsoleColor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/HP/OneDrive - De Vinci/Documents/Cours/ESILV 4A IF/MyWorkspace/PricerOptions_LastVersion/ConsoleColor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ConsoleColor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ConsoleColor.cpp$(DependSuffix): ConsoleColor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ConsoleColor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ConsoleColor.cpp$(DependSuffix) -MM ConsoleColor.cpp

$(IntermediateDirectory)/ConsoleColor.cpp$(PreprocessSuffix): ConsoleColor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ConsoleColor.cpp$(PreprocessSuffix) ConsoleColor.cpp

$(IntermediateDirectory)/AsianOption.cpp$(ObjectSuffix): AsianOption.cpp $(IntermediateDirectory)/AsianOption.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/HP/OneDrive - De Vinci/Documents/Cours/ESILV 4A IF/MyWorkspace/PricerOptions_LastVersion/AsianOption.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/AsianOption.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/AsianOption.cpp$(DependSuffix): AsianOption.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/AsianOption.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/AsianOption.cpp$(DependSuffix) -MM AsianOption.cpp

$(IntermediateDirectory)/AsianOption.cpp$(PreprocessSuffix): AsianOption.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/AsianOption.cpp$(PreprocessSuffix) AsianOption.cpp

$(IntermediateDirectory)/EuropeanOption.cpp$(ObjectSuffix): EuropeanOption.cpp $(IntermediateDirectory)/EuropeanOption.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/HP/OneDrive - De Vinci/Documents/Cours/ESILV 4A IF/MyWorkspace/PricerOptions_LastVersion/EuropeanOption.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EuropeanOption.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EuropeanOption.cpp$(DependSuffix): EuropeanOption.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EuropeanOption.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EuropeanOption.cpp$(DependSuffix) -MM EuropeanOption.cpp

$(IntermediateDirectory)/EuropeanOption.cpp$(PreprocessSuffix): EuropeanOption.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EuropeanOption.cpp$(PreprocessSuffix) EuropeanOption.cpp

$(IntermediateDirectory)/BlackScholes.cpp$(ObjectSuffix): BlackScholes.cpp $(IntermediateDirectory)/BlackScholes.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/HP/OneDrive - De Vinci/Documents/Cours/ESILV 4A IF/MyWorkspace/PricerOptions_LastVersion/BlackScholes.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BlackScholes.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BlackScholes.cpp$(DependSuffix): BlackScholes.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BlackScholes.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BlackScholes.cpp$(DependSuffix) -MM BlackScholes.cpp

$(IntermediateDirectory)/BlackScholes.cpp$(PreprocessSuffix): BlackScholes.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BlackScholes.cpp$(PreprocessSuffix) BlackScholes.cpp

$(IntermediateDirectory)/CRR.cpp$(ObjectSuffix): CRR.cpp $(IntermediateDirectory)/CRR.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/HP/OneDrive - De Vinci/Documents/Cours/ESILV 4A IF/MyWorkspace/PricerOptions_LastVersion/CRR.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CRR.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CRR.cpp$(DependSuffix): CRR.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CRR.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CRR.cpp$(DependSuffix) -MM CRR.cpp

$(IntermediateDirectory)/CRR.cpp$(PreprocessSuffix): CRR.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CRR.cpp$(PreprocessSuffix) CRR.cpp

$(IntermediateDirectory)/AmericanOption.cpp$(ObjectSuffix): AmericanOption.cpp $(IntermediateDirectory)/AmericanOption.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/HP/OneDrive - De Vinci/Documents/Cours/ESILV 4A IF/MyWorkspace/PricerOptions_LastVersion/AmericanOption.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/AmericanOption.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/AmericanOption.cpp$(DependSuffix): AmericanOption.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/AmericanOption.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/AmericanOption.cpp$(DependSuffix) -MM AmericanOption.cpp

$(IntermediateDirectory)/AmericanOption.cpp$(PreprocessSuffix): AmericanOption.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/AmericanOption.cpp$(PreprocessSuffix) AmericanOption.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


