##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=lab10_ex3
ConfigurationName      :=Debug
WorkspacePath          :="C:/Users/rfran/OneDrive/Documents/POLITECNICO/2 ANNO/1 semestre/APA/PROGRAMMAZIONE"
ProjectPath            :="C:/Users/rfran/OneDrive/Documents/POLITECNICO/2 ANNO/1 semestre/APA/PROGRAMMAZIONE/LAB codelite/L8-10/L10/lab10_ex3"
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=rfran
Date                   :=13/10/2021
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :="C:/Program Files/CodeBlocks/MinGW/bin/g++.exe"
SharedObjectLinkerName :="C:/Program Files/CodeBlocks/MinGW/bin/g++.exe" -shared -fPIC
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
ObjectsFileList        :="lab10_ex3.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :="C:/Program Files/CodeBlocks/MinGW/bin/windres.exe"
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
AR       := "C:/Program Files/CodeBlocks/MinGW/bin/ar.exe" rcu
CXX      := "C:/Program Files/CodeBlocks/MinGW/bin/g++.exe"
CC       := "C:/Program Files/CodeBlocks/MinGW/bin/gcc.exe"
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := "C:/Program Files/CodeBlocks/MinGW/bin/as.exe"


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/pgList.c$(ObjectSuffix) $(IntermediateDirectory)/inv.c$(ObjectSuffix) $(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/pg.c$(ObjectSuffix) $(IntermediateDirectory)/invArray.c$(ObjectSuffix) $(IntermediateDirectory)/equipArray.c$(ObjectSuffix) 



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
$(IntermediateDirectory)/pgList.c$(ObjectSuffix): pgList.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pgList.c$(ObjectSuffix) -MF$(IntermediateDirectory)/pgList.c$(DependSuffix) -MM pgList.c
	$(CC) $(SourceSwitch) "C:/Users/rfran/OneDrive/Documents/POLITECNICO/2 ANNO/1 semestre/APA/PROGRAMMAZIONE/LAB codelite/L8-10/L10/lab10_ex3/pgList.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pgList.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pgList.c$(PreprocessSuffix): pgList.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pgList.c$(PreprocessSuffix) pgList.c

$(IntermediateDirectory)/inv.c$(ObjectSuffix): inv.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/inv.c$(ObjectSuffix) -MF$(IntermediateDirectory)/inv.c$(DependSuffix) -MM inv.c
	$(CC) $(SourceSwitch) "C:/Users/rfran/OneDrive/Documents/POLITECNICO/2 ANNO/1 semestre/APA/PROGRAMMAZIONE/LAB codelite/L8-10/L10/lab10_ex3/inv.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/inv.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/inv.c$(PreprocessSuffix): inv.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/inv.c$(PreprocessSuffix) inv.c

$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c
	$(CC) $(SourceSwitch) "C:/Users/rfran/OneDrive/Documents/POLITECNICO/2 ANNO/1 semestre/APA/PROGRAMMAZIONE/LAB codelite/L8-10/L10/lab10_ex3/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/pg.c$(ObjectSuffix): pg.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pg.c$(ObjectSuffix) -MF$(IntermediateDirectory)/pg.c$(DependSuffix) -MM pg.c
	$(CC) $(SourceSwitch) "C:/Users/rfran/OneDrive/Documents/POLITECNICO/2 ANNO/1 semestre/APA/PROGRAMMAZIONE/LAB codelite/L8-10/L10/lab10_ex3/pg.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pg.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pg.c$(PreprocessSuffix): pg.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pg.c$(PreprocessSuffix) pg.c

$(IntermediateDirectory)/invArray.c$(ObjectSuffix): invArray.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/invArray.c$(ObjectSuffix) -MF$(IntermediateDirectory)/invArray.c$(DependSuffix) -MM invArray.c
	$(CC) $(SourceSwitch) "C:/Users/rfran/OneDrive/Documents/POLITECNICO/2 ANNO/1 semestre/APA/PROGRAMMAZIONE/LAB codelite/L8-10/L10/lab10_ex3/invArray.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/invArray.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/invArray.c$(PreprocessSuffix): invArray.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/invArray.c$(PreprocessSuffix) invArray.c

$(IntermediateDirectory)/equipArray.c$(ObjectSuffix): equipArray.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/equipArray.c$(ObjectSuffix) -MF$(IntermediateDirectory)/equipArray.c$(DependSuffix) -MM equipArray.c
	$(CC) $(SourceSwitch) "C:/Users/rfran/OneDrive/Documents/POLITECNICO/2 ANNO/1 semestre/APA/PROGRAMMAZIONE/LAB codelite/L8-10/L10/lab10_ex3/equipArray.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/equipArray.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/equipArray.c$(PreprocessSuffix): equipArray.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/equipArray.c$(PreprocessSuffix) equipArray.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


