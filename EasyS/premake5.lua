project "EasyS"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir("../bin/" .. outputdir .. "/%{prj.name}")
    objdir("../bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.cpp",
        "src/**.h"
    }

    includedirs
    {
        "vendor/spdlog/include"
    }

    defines
    {
        "EZ_PLATFORM_WINDOWS",
        "EZ_BUILD_DLL"
    }
    
    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Project")
    }

    filter {"configurations:Debug"}
        buildoptions "/MTd"
        runtime "Debug"
        symbols "on"

    filter {"configurations:Release"}
        buildoptions "/MT"
        runtime "Release"
        optimize "on"