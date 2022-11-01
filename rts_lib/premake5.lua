project "rts_lib"  
    kind "StaticLib" 
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "rtspch.h"
    pchsource "src/rtspch.cpp"
    
    files {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "src",
        "%{IncludeDir.SDL}",
        "%{IncludeDir.SDL_ttf}",
        "%{IncludeDir.SDL_image}",
        "%{IncludeDir.spdlog}"
    }

    libdirs
    {
        "%{LibraryDir.SDL}",
        "%{LibraryDir.SDL_ttf}",
        "%{LibraryDir.SDL_image}"
    }

    links
    {
        "SDL2",
        "SDL2main",
        "SDL2_ttf",
        "SDL2_image"
    }

    --[[prebuildcommands
    {
        "cd",
        '{COPYFILE} "%{wks.location}vendor/SDL2-2.0.22/lib/*.dll" "%{wks.location}%{prj.name}"',
        '{COPYFILE} "%{wks.location}vendor/SDL2_ttf-2.0.15/dlls/*.dll" "%{wks.location}%{prj.name}"',
        '{COPYFILE} "%{wks.location}vendor/SDL2_image-2.0.5/dlls/*.dll" "%{wks.location}%{prj.name}"',
        ('{COPYFILE} "%{wks.location}vendor/SDL2-2.0.22/lib/*.dll" "%{wks.location}bin/"' .. outputdir .. '"/%{prj.name}'),
        ('{COPYFILE} "%{wks.location}vendor/SDL2_ttf-2.0.15/dlls/*.dll" "%{wks.location}bin/"' .. outputdir .. '"/%{prj.name}'),
        ('{COPYFILE} "%{wks.location}vendor/SDL2_image-2.0.5/dlls/*.dll" "%{wks.location}bin/"' .. outputdir .. '"/%{prj.name}'),
    }]]

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

    