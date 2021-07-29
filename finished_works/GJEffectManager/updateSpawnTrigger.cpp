void GJEffectManager::updateSpawnTriggers(float delta) {
    int index = 0;
    while (index < this->spawnActions->count()) {
        SpawnTriggerAction* action = this->spawnActions->objectAtIndex(index);

        if (!action->timerEnded) {
            action->timer += delta;
        }
        action->timerEnded = action->timer >= action->delay;

        if (action->timerEnded) {
                if (this->gameLayer) {
                        this->gameLayer->spawnGroupTriggered(action->groupid);
                }
                this->spawnActions->removeObjectAtIndex(index);
        } else {
            index++;
        }
    }
    return;
}