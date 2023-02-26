// chatgpt-cpp - https://github.com/Apex-master

#include "TextEditor.h"
#include "openai_api_client.h"
#include "icons.h"

void CreateHeader(const char* text)
{
    auto windowWidth = ImGui::GetWindowSize().x;
    ImGui::SetCursorPosX((windowWidth - ImGui::CalcTextSize(text).x) * 0.5f);
    ImGui::Text(text);
    ImGui::Spacing();
    ImGui::Separator();
}

void AIPlayground(HWND hwnd)
{
    // Get the dimensions of the CreateWindow window
    RECT windowRect;
    GetClientRect(hwnd, &windowRect);
    int windowWidth = windowRect.right - windowRect.left;
    int windowHeight = windowRect.bottom - windowRect.top;

    // Set the size and position of the ImGui window
    ImGui::SetNextWindowSize(ImVec2(windowWidth, windowHeight));
    ImGui::SetNextWindowPos(ImVec2(windowWidth / 2, windowHeight / 2), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    ImGui::Begin("chatgpt-cpp", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar);

    ImGui::BeginChild("Styles", ImVec2(101.0f, ImGui::GetWindowHeight() - 114.0f), true);

    CreateHeader("Styles");
    ImGui::Spacing();

    const ImVec4 active = ImColor(0, 100, 200, 255);
    const ImVec4 inactive = ImColor(31, 30, 31, 255);

    ImGui::PushStyleColor(ImGuiCol_Button, aiStyle == 0 ? active : inactive);
    if (ImGui::Button(ICON_FA_HOUSE, ImVec2(100 - 15, 41)))
    {
        aiStyle = 0;
    }
    if (ImGui::IsItemHovered()) 
    {
        ImGui::SetTooltip("Default Style");
    }

    ImGui::Spacing();
    ImGui::PushStyleColor(ImGuiCol_Button, aiStyle == 1 ? active : inactive);
    if (ImGui::Button(ICON_FA_MAILBOX, ImVec2(100 - 15, 41)))
    {
        aiStyle = 1;
    }
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip("Write a professional and smart email");
    }

    ImGui::Spacing();
    ImGui::PushStyleColor(ImGuiCol_Button, aiStyle == 2 ? active : inactive);
    if (ImGui::Button(ICON_FA_COMMENTS, ImVec2(100 - 15, 41)))
    {
        aiStyle = 2;
    }
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip("Explain a topic to a non-technical audience");
    }

    ImGui::Spacing();
    ImGui::PushStyleColor(ImGuiCol_Button, aiStyle == 3 ? active : inactive);
    if (ImGui::Button(ICON_FA_PENCIL, ImVec2(100 - 15, 41)))
    {
        aiStyle = 3;
    }
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip("Write a short story");
    }

    ImGui::Spacing();
    ImGui::PushStyleColor(ImGuiCol_Button, aiStyle == 4 ? active : inactive);
    if (ImGui::Button(ICON_FA_NEWSPAPER, ImVec2(100 - 15, 41)))
    {
        aiStyle = 4;
    }
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip("Write a news article");
    }

    ImGui::Spacing();
    ImGui::PushStyleColor(ImGuiCol_Button, aiStyle == 5 ? active : inactive);
    if (ImGui::Button(ICON_FA_GRADUATION_CAP, ImVec2(100 - 15, 41)))
    {
        aiStyle = 5;
    }
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip("Write an academic paper");
    }

    ImGui::Spacing();
    ImGui::PushStyleColor(ImGuiCol_Button, aiStyle == 6 ? active : inactive); 
    if (ImGui::Button(ICON_FA_SHOPPING_BAG, ImVec2(100 - 15, 41)))
    {
        aiStyle = 6;
    }
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip("Write a marketing copy for a product or service");
    }

    ImGui::Spacing();
    ImGui::PushStyleColor(ImGuiCol_Button, aiStyle == 7 ? active : inactive); 
    if (ImGui::Button(ICON_FA_HASHTAG, ImVec2(100 - 15, 41)))
    {
        aiStyle = 7;
    }
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip("Write a social media post");
    }

    ImGui::Spacing();
    ImGui::PushStyleColor(ImGuiCol_Button, aiStyle == 8 ? active : inactive); 
    if (ImGui::Button(ICON_FA_CODE, ImVec2(100 - 15, 41)))
    {
        aiStyle = 8;
    }
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip("Write C++ Window Kernel Driver code");
    }
        
    ImGui::Spacing();
    ImGui::PushStyleColor(ImGuiCol_Button, aiStyle == 9 ? active : inactive); 
    if (ImGui::Button(ICON_FA_GAVEL, ImVec2(100 - 15, 41)))
    {
        aiStyle = 9;
    }
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip("Write a legal document");
    }
            
    ImGui::Spacing();
    ImGui::PushStyleColor(ImGuiCol_Button, aiStyle == 10 ? active : inactive);
    if (ImGui::Button(ICON_FA_SQUIRREL, ImVec2(100 - 15, 41)))
    {
        aiStyle = 10;
    }
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip("Write a professional resume for a job position");
    }
           
    ImGui::PopStyleColor(11);
    ImGui::SetCursorPosY(ImGui::GetWindowHeight() - 10);

    ImGui::EndChild();

    ImGui::SameLine();

    ImGui::BeginChild("chatgpt-cpp", ImVec2(windowWidth - 410.0f, ImGui::GetWindowHeight() - 114.0f), true);
    {
        CreateHeader("chatgpt-cpp");
        ImGui::Spacing();
        aiEditor.Render("##chatgpt-cpp", ImVec2(windowWidth - 426.0f, ImGui::GetWindowHeight() - 50.0f));
        aiEditor.SetShowWhitespaces(false);
        aiEditor.SetReadOnly(false);
        aiEditor.SetPalette(TextEditor::GetDarkPalette());
    }
    ImGui::EndChild();

    ImGui::SameLine();

    ImGui::BeginChild("Options", ImVec2(280.0f, ImGui::GetWindowHeight() - 114.0f), true);
    CreateHeader("Options");
    ImGui::Spacing();
    ImGui::PushItemWidth((120.0f));
    
    char apiKeyChar[256];
    strcpy_s(apiKeyChar, apiKey.c_str());
    ImGui::InputText("API Key", apiKeyChar, sizeof(apiKeyChar));
    apiKey = apiKeyChar;

    ImGui::Combo("Model", &modelIndex, modelOptions, IM_ARRAYSIZE(modelOptions));
    ImGui::InputInt("Max Tokens", &maxTokens);
    ImGui::InputFloat("Temperature", &temperature);
    ImGui::InputInt("Number of Samples", &n);
    ImGui::InputFloat("Presence Penalty", &presencePenalty);
    ImGui::InputInt("Number of Trials", &bestOf);
    ImGui::Checkbox("Enable Echo", &echo);

    ImGui::Spacing();
    ImGui::BeginChild("Log", ImVec2(262.0f, -1), true);
    CreateHeader("Log");
    ImGui::Spacing();

    logEditor.Render("##LogEditor", ImVec2(-1, -1));
    logEditor.SetShowWhitespaces(false);
    logEditor.SetReadOnly(true);
    logEditor.SetPalette(TextEditor::GetDarkPalette());

    ImGui::EndChild();

    ImGui::EndChild();

    ImGui::BeginChild("Input", ImVec2(windowWidth - 16.0f, 94), true);
    {
        char searchTermChar[2048];
        strcpy_s(searchTermChar, inputText.c_str());
        ImGui::InputTextMultiline("##Input", searchTermChar, IM_ARRAYSIZE(searchTermChar), ImVec2(windowWidth - 127.0f, -1), ImGuiInputTextFlags_AllowTabInput);
        inputText = searchTermChar;

        ImGui::SameLine(windowWidth - 112.0f);

        if (waiting)
        {
            ImGui::PushStyleVar(ImGuiStyleVar_Alpha, ImGui::GetStyle().Alpha * 0.5f);
        }

        if (ImGui::Button("Submit", ImVec2(-1, -1)) && !waiting)
        {
            if (apiKey != "")
            {
                std::thread t(SendRequest);
                t.detach();
            }
            else
            {
                logEditor.InsertText("[-] Please ensure that you fill out the API field, as it appears to be empty or incomplete\n");
            }
        }
        ImGui::PopStyleVar();
    }
    ImGui::EndChild();

    ImGui::End();
}
