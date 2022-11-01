include "dependencies"

workspace "SoundGame"
    startproject "SoundGame_01"
    architecture "x86_64"
    configurations { "Debug", "Release" }

    flags
	{
		"MultiProcessorCompile"
	}
        

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "rts_lib"
include "SoundGame_01"