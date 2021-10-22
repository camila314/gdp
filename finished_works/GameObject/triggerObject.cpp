GameObject::triggerObject(int arg1) {
    float speed;
    switch (m_objectID) {
        case 200:
            speed = 0.70;
            break;
        case 201:
            speed = 0.9;
            break;
        case 202:
            speed = 1.10;
            break;
        case 203:
            speed = 1.30;
            break;
        case 1334:
            speed = 1.60;
        default:
            return;
    }

    PL->updateTimeMod(rdi,speed, false);
    this->playShineEffect();
    PL->addToSpeedObjects(PL, this);
}