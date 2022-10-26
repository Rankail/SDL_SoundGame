project "SoundGame_01"  
    kind "ConsoleApp" 
    language "C++"
    cppdialect "C++20"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")
    
    files {
        "src/**.hpp",
        "src/**.cpp"
    }

    includedirs
    {
        "src",
        "%{IncludeDir.SDL}",
        "%{IncludeDir.SDL_ttf}",
        "%{IncludeDir.SDL_image}"
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

    