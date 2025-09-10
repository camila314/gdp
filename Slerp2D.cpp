#include <complex>
float Slerp2D(float fromAngle, float toAngle, float t) {
    std::complex<float> fromVec = std::polar(1.0f, fromAngle * 0.5f);
    std::complex<float> toVec = std::polar(1.0f, toAngle * 0.5f);


    float dot = std::real(fromVec) * std::real(toVec) + std::imag(fromVec) * std::imag(toVec);
    if (dot < 0.0f) {
        dot *= -1;
        toVec *=  -1;
    }

    std::complex<float> weight = std::complex(1.0f - t, t);
    if (dot < 0.9999) {
        float between = std::acos(dot);

        weight *= between;
        weight = std::complex(std::sin(weight.real()), std::sin(weight.imag()));
        weight /= std::sin(between);
    }

    std::complex<float> interpVec = (weight.imag() * toVec) + (weight.real() * fromVec);
    return std::atan2(std::imag(interpVec), std::real(interpVec)) * 2.0f;
}