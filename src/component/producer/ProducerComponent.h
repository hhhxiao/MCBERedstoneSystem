//
// Created by xhy on 2021/3/16.
//

#ifndef MCBEREDSTONESYSTEM_PRODUCERCOMPONENT_H
#define MCBEREDSTONESYSTEM_PRODUCERCOMPONENT_H

#include "component/BaseCircuitComponent.h"

class CircuitSceneGraph;

class ProducerComponent : public BaseCircuitComponent {
    int mNextStrength = 0;
    bool mStopPower = false;
    bool mAttachedAllowed = false;

public:
    void allowAttachments(bool attached);

    bool allowConnection(CircuitSceneGraph &graph, const CircuitTrackingInfo &info, bool bDirectlyPowered);

    bool canStopPower() const {
        return this->mStopPower;
    }

    bool doesAllowAttachments() const {
        return this->mAttachedAllowed;
    }

    bool evaluate(CircuitSystem &, const BlockPos &) override;

    ComponentTypeID getBaseType() override;

    ComponentTypeID getInstanceType() override;

    void setStrength(int strength) override;

};

class CapacitorComponent : public ProducerComponent {
    ComponentTypeID getBaseType() override;

    ComponentTypeID getInstanceType() override;

    FACING getPowerOutDirection() const { return FACING::NOT_DEFINED; }
};

#endif //MCBEREDSTONESYSTEM_PRODUCERCOMPONENT_H
