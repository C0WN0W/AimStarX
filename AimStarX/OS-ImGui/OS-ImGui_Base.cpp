#include "OS-ImGui_Base.h"
#include "Fonts.hpp"

namespace OSImGui
{
    bool OSImGui_Base::InitImGui(ID3D11Device* device, ID3D11DeviceContext* device_context)
    {
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;

        ImFontAtlas* fontAtlas = new ImFontAtlas();
        ImFontConfig arialConfig;
        arialConfig.FontDataOwnedByAtlas = false;

        ImFont* arialFont = fontAtlas->AddFontFromMemoryTTF(Fonts::Rainbow, sizeof Fonts::Rainbow, 20.f, &arialConfig, io.Fonts->GetGlyphRangesCyrillic());

        io.Fonts = fontAtlas;

        ImFont* TitleFont = io.Fonts->AddFontFromMemoryTTF(Fonts::Corna, sizeof Fonts::Corna, 30.f);
        ImFont* ChineseFont = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ebrimabd.ttf", 20.0f, &arialConfig, io.Fonts->GetGlyphRangesChineseFull());

        ImGui::StyleColorsDark();
        io.LogFilename = nullptr;

        if (!ImGui_ImplWin32_Init(Window.hWnd))
            throw OSException("ImGui_ImplWin32_Init() call failed.");
        if (!ImGui_ImplDX11_Init(device, device_context))
            throw OSException("ImGui_ImplDX11_Init() call failed.");

        return true;
    }

    void OSImGui_Base::CleanImGui()
    {
        ImGui_ImplDX11_Shutdown();
        ImGui_ImplWin32_Shutdown();
        ImGui::DestroyContext();

        if(g_Device.g_pd3dDevice)
            g_Device.CleanupDeviceD3D();

        // Only destroy window in external mode.
        if (Window.hWnd && !Window.Name.empty())
        {
            DestroyWindow(Window.hWnd);
            UnregisterClassA(Window.ClassName.c_str(), Window.hInstance);
        }
    }

    std::wstring OSImGui_Base::StringToWstring(std::string& str)
    {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        return converter.from_bytes(str);
    }

}