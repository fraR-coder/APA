##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lab11_ex3
ConfigurationName      :=Debug
WorkspacePath          :="C:/Users/rfran/OneDrive/Documents/POLITECNICO/2 ANNO/APA/PROGRAMMAZIONE"
ProjectPath            :="C:/Users/rfran/OneDrive/Documents/POLITECNICO/2 ANNO/APA/PROGRAMMAZIONE/LAB codelite/L11/Lab11_ex3"
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=rfran
Date                   :=22/01/2021
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
ObjectsFileList        :="Lab11_ex3.txt"
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
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/grafo.c$(ObjectSuffix) $(IntermediateDirectory)/tabella_di_simboli.c$(ObjectSuffix) 



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
	$(CC) $(SourceSwitch) "C:/Users/rfran/OneDrive/Documents/POLITECNICO/2 ANNO/APA/PROGRAMMAZIONE/LAB codelite/L11/Lab11_ex3/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/grafo.c$(ObjectSuffix): grafo.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/grafo.c$(ObjectSuffix) -MF$(IntermediateDirectory)/grafo.c$(DependSuffix) -MM grafo.c
	$(CC) $(SourceSwitch) "C:/Users/rfran/OneDrive/Documents/POLITECNICO/2 ANNO/APA/PROGRAMMAZIONE/LAB codelite/L11/Lab11_ex3/grafo.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/grafo.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/grafo.c$(PreprocessSuffix): grafo.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/grafo.c$(PreprocessSuffix) grafo.c

$(IntermediateDirectory)/tabella_di_simboli.c$(ObjectSuffix): tabella_di_simboli.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tabella_di_simboli.c$(ObjectSuffix) -MF$(IntermediateDirectory)/tabella_di_simboli.c$(DependSuffix) -MM tabella_di_simboli.c
	$(CC) $(SourceSwitch) "C:/Users/rfran/OneDrive/Documents/POLITECNICO/2 ANNO/APA/PROGRAMMAZIONE/LAB codelite/L11/Lab11_ex3/tabella_di_simboli.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tabella_di_simboli.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tabella_di_simboli.c$(PreprocessSuffix): tabella_di_simboli.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tabella_di_simboli.c$(PreprocessSuffix) tabella_di_simboli.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


