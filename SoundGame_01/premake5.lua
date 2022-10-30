project "SoundGame_01"  
    kind "ConsoleApp" 
    language "C++"
    cppdialect "C++17"

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

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

    