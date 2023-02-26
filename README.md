# chatgpt-cpp
chatgpt-cpp is a conversational AI software application built in C++ using OpenAI GPT to generate natural language responses to user inputs. It features a user-friendly interface powered by Dear ImGui library, with multiple settings to modify API requests.

* Playground UI (chatgpt-cpp/playground.h)
* OpenAI API (chatgpt-cpp/openai_api_client.h)

## Main Features

* Uses the OpenAI GPT model for generating responses.
* Provides a user-friendly interface powered by Dear ImGui library.
* Multiple settings to modify API requests, such as temperature and max_tokens values.
* Multiple AI styles that implement prompts before the user's question to personalize the conversation.

<b>Screenshots:</b>
![screenshot](https://github.com/Apex-master/chatgpt-cpp/blob/main/screenshot1.png)
![screenshot](https://github.com/Apex-master/chatgpt-cpp/blob/main/screenshot2.png)

## How it works
It uses the OpenAI GPT model, which is a transformer-based neural network that has been pre-trained on a large corpus of text data, to generate responses to user inputs. The application sends the user input to the GPT model API, which returns a sequence of tokens that represent the model's generated response.

To improve the quality and relevance of the responses, ChatGPT-CPP includes multiple AI styles that implement prompts before the user's question. These prompts provide additional context for the GPT model to generate a more relevant and appropriate response.

The application provides a user-friendly interface powered by the Dear ImGui library, which allows users to interact with the chatbot and modify API requests. The user can adjust settings such as the temperature and presencePenalty values, which control the randomness and creativity of the model's responses. These settings can be fine-tuned to improve the quality of the conversation and tailor the chatbot's responses to the user's preferences.

## To do
* Multi-turn conversations (no sessions available yet for OpenAI API)

## Credits:
* [OpenAI](https://openai.com)
* [imgui](https://github.com/ocornut/imgui)
* [ImGuiColorTextEdit](https://github.com/BalazsJako/ImGuiColorTextEdit)
* [curl](https://github.com/curl/curl)
