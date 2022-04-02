##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=L12_ex1
ConfigurationName      :=Debug
WorkspacePath          :="C:/Users/rfran/OneDrive/Documents/POLITECNICO/2 ANNO/APA/PROGRAMMAZIONE"
ProjectPath            :="C:/Users/rfran/OneDrive/Documents/POLITECNICO/2 ANNO/APA/PROGRAMMAZIONE/LAB codelite/L12/L12_ex1"
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=rfran
Date                   :=14/01/2021
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :="C:/Program Files (x86)/CodeBlocks/MinGW/bin/g++.exe"
SharedObjectLinkerName :="C:/Program Files (x86)/CodeBlocks/MinGW/bin/g++.exe" -shared -fPIC
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
ObjectsFileList        :="L12_ex1.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :="C:/Program Files (x86)/CodeBlocks/MinGW/bin/windres.exe"
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
AR       := "C:/Program Files (x86)/CodeBlocks/MinGW/bin/ar.exe" rcu
CXX      := "C:/Program Files (x86)/CodeBlocks/MinGW/bin/g++.exe"
CC       := "C:/Program Files (x86)/CodeBlocks/MinGW/bin/gcc.exe"
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := "C:/Program Files (x86)/CodeBlocks/MinGW/bin/as.exe"


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/titoli.c$(ObjectSuffix) $(IntermediateDirectory)/data.c$(ObjectSuffix) $(IntermediateDirectory)/quotazioni.c$(ObjectSuffix) 



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
	@$(MakeDirCommand) "$(ConfigurationName)"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(ConfigurationName)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c
	$(CC) $(SourceSwitch) "C:/Users/rfran/OneDrive/Documents/POLITECNICO/2 ANNO/APA/PROGRAMMAZIONE/LAB codelite/L12/L12_ex1/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/titoli.c$(ObjectSuffix): titoli.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/titoli.c$(ObjectSuffix) -MF$(IntermediateDirectory)/titoli.c$(DependSuffix) -MM titoli.c
	$(CC) $(SourceSwitch) "C:/Users/rfran/OneDrive/Documents/POLITECNICO/2 ANNO/APA/PROGRAMMAZIONE/LAB codelite/L12/L12_ex1/titoli.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/titoli.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/titoli.c$(PreprocessSuffix): titoli.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/titoli.c$(PreprocessSuffix) titoli.c

$(IntermediateDirectory)/data.c$(ObjectSuffix): data.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/data.c$(ObjectSuffix) -MF$(IntermediateDirectory)/data.c$(DependSuffix) -MM data.c
	$(CC) $(SourceSwitch) "C:/Users/rfran/OneDrive/Documents/POLITECNICO/2 ANNO/APA/PROGRAMMAZIONE/LAB codelite/L12/L12_ex1/data.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/data.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/data.c$(PreprocessSuffix): data.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/data.c$(PreprocessSuffix) data.c

$(IntermediateDirectory)/quotazioni.c$(ObjectSuffix): quotazioni.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/quotazioni.c$(ObjectSuffix) -MF$(IntermediateDirectory)/quotazioni.c$(DependSuffix) -MM quotazioni.c
	$(CC) $(SourceSwitch) "C:/Users/rfran/OneDrive/Documents/POLITECNICO/2 ANNO/APA/PROGRAMMAZIONE/LAB codelite/L12/L12_ex1/quotazioni.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/quotazioni.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quotazioni.c$(PreprocessSuffix): quotazioni.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quotazioni.c$(PreprocessSuffix) quotazioni.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


