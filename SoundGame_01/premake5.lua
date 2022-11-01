project "SoundGame_01"  
    kind "ConsoleApp" 
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")
    
    files {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
		"%{wks.location}/rts_lib/src",
        "%{IncludeDir.SDL}",
        "%{IncludeDir.SDL_ttf}",
        "%{IncludeDir.SDL_image}",
        "%{IncludeDir.spdlog}"
    }

    links
    {
        "rts_lib"
    }

    prebuildcommands
    {
        '{COPYFILE} "%{wks.location}vendor/SDL2-2.0.22/lib/*.dll" "%{wks.location}%{prj.name}"',
        '{COPYFILE} "%{wks.location}vendor/SDL2_ttf-2.0.15/dlls/*.dll" "%{wks.location}%{prj.name}"',
        '{COPYFILE} "%{wks.location}vendor/SDL2_image-2.0.5/dlls/*.dll" "%{wks.location}%{prj.name}"',
        ('{COPYDIR} "%{wks.location}SoundGame_01/rsc" "%{wks.location}bin/"' .. outputdir .. '"/%{prj.name}/rsc"'),
        ('{COPYFILE} "%{wks.location}vendor/SDL2-2.0.22/lib/*.dll" "%{wks.location}bin/"' .. outputdir .. '"/%{prj.name}'),
        ('{COPYFILE} "%{wks.location}vendor/SDL2_ttf-2.0.15/dlls/*.dll" "%{wks.location}bin/"' .. outputdir .. '"/%{prj.name}'),
        ('{COPYFILE} "%{wks.location}vendor/SDL2_image-2.0.5/dlls/*.dll" "%{wks.location}bin/"' .. outputdir .. '"/%{prj.name}'),
    }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "Full"

    