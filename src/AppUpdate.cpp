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
        m_Giraffe->SetPosition(glm::vec2(pos.x, pos.y+3));
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::DOWN)) {
        const glm::vec2& pos=m_Giraffe->GetPosition();
        m_Giraffe->SetPosition(glm::vec2(pos.x, pos.y-3));
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::LEFT)) {
        const glm::vec2& pos=m_Giraffe->GetPosition();
        m_Giraffe->SetPosition(glm::vec2(pos.x-3, pos.y));
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::RIGHT)) {
        const glm::vec2& pos=m_Giraffe->GetPosition();
        m_Giraffe->SetPosition(glm::vec2(pos.x+3, pos.y));
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }
    if (((abs(m_Giraffe->GetPosition().x-m_Chest->GetPosition().x)<3)&&(abs(m_Giraffe->GetPosition().y-m_Chest->GetPosition().y)<3))&&m_Phase==Phase::COLLIDE_DETECTION) {
       m_Chest->SetVisible(false);

    }
    if (m_Phase==Phase::BEE_ANIMATION) {
        m_Bee->SetLooping(true);
        m_Bee->SetPlaying(true);

    }
    for (int i=0;i<3;i++) {
        const glm::vec2& Gpos=m_Giraffe->GetPosition();
        const glm::vec2& Dpos=m_Doors[i]->GetPosition();
        if (abs(Gpos.x-Dpos.x)<10 && abs(Gpos.y-Dpos.y)<15&&m_Phase==Phase::OPEN_THE_DOORS) {
            m_Doors[i]->SetImage(GA_RESOURCE_DIR"/Image/Character/door_open.png");
        }
    }
    if (m_Phase==Phase::COUNTDOWN) {
        if (m_Ball->IfAnimationEnds()) {
            m_Ball->SetVisible(false);
            m_Ball->SetPlaying(false);
        }else {
            m_Ball->SetVisible(true);
            m_Ball->SetPlaying(true);
        }

    }


    if (m_EnterDown) {
        if (!Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
            ValidTask();
        }
    }
    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    m_Root.Update();
}
