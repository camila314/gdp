float Slerp2D(float startAngle, float endAngle, float t) {
    float halfStart = startAngle * 0.5f;
    float halfEnd   = endAngle * 0.5f;

    float cosStart = cosf(halfStart);
    float sinStart = sinf(halfStart);
    float cosEnd   = cosf(halfEnd);
    float sinEnd   = sinf(halfEnd);

    float dot = (cosStart * cosEnd) + (sinStart * sinEnd);

    float weightStart, weightEnd;
    if (dot < 0.f) {
        dot = -dot;
        sinEnd = -sinEnd;
        cosEnd = -cosEnd;
    }

    if (1.f - dot > 0.0001f) {
        float theta = acosf(dot);
        float sinTheta = sinf(theta);
        weightStart = sinf(theta * (1.f - t)) / sinTheta;
        weightEnd   = sinf(theta * t) / sinTheta;
    } else {
        weightStart = 1.f - t;
        weightEnd   = t;
    }

    float interpSin = (sinStart * weightStart) + (sinEnd * weightEnd);
    float interpCos = (cosStart * weightStart) + (cosEnd * weightEnd);

    double out = atan2(interpSin, interpCos);
    return out + out;
}