#include "App.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

void App::Update() {

    // TODO: Add your own logics to finish the tasks in README.md

    /*
     *  Do not touch the code below as they serve the purpose for validating the tasks,
     *  rendering the frame, and exiting the game.
    */
    if (Util::Input::IsKeyPressed(Util::Keycode::UP)) {
        const glm::vec2& pos=m_Giraffe->GetPosition();
        m_Giraffe->SetPosition(glm::vec2(pos.x, pos.y+1));
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::DOWN)) {
        const glm::vec2& pos=m_Giraffe->GetPosition();
        m_Giraffe->SetPosition(glm::vec2(pos.x, pos.y-1));
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::LEFT)) {
        const glm::vec2& pos=m_Giraffe->GetPosition();
        m_Giraffe->SetPosition(glm::vec2(pos.x-1, pos.y));
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::RIGHT)) {
        const glm::vec2& pos=m_Giraffe->GetPosition();
        m_Giraffe->SetPosition(glm::vec2(pos.x+1, pos.y));
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }
    if ((abs(m_Giraffe->GetPosition().x-m_Chest->GetPosition().x)<1)||(abs(m_Giraffe->GetPosition().y-m_Chest->GetPosition().y)<1)) {
       m_Chest->SetVisible(false);

    }



    if (m_EnterDown) {
        if (!Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
            ValidTask();
        }
    }
    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    m_Root.Update();
}
