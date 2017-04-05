#ifndef HSS_AvgResynchInfoDt_h
#define HSS_AvgResynchInfoDt_h

#include <string>

class HSS_AvgResynchInfoDt {
public:
    HSS_AvgResynchInfoDt(): rand(), auts() {};
    HSS_AvgResynchInfoDt(const HSS_AvgResynchInfoDt& old): rand(old.rand), auts(old.auts) {};
    ~HSS_AvgResynchInfoDt() {};

    HSS_AvgResynchInfoDt& operator=(const HSS_AvgResynchInfoDt&);
    friend bool operator==(const HSS_AvgResynchInfoDt&, const HSS_AvgResynchInfoDt&);
    friend bool operator!=(const HSS_AvgResynchInfoDt&, const HSS_AvgResynchInfoDt&);

    std::string rand;
    std::string auts;
};

inline HSS_AvgResynchInfoDt& HSS_AvgResynchInfoDt::operator=(const HSS_AvgResynchInfoDt& other) {
    rand = other.rand;
    auts = other.auts;
    return *this;
}

inline bool operator==(const HSS_AvgResynchInfoDt& left, const HSS_AvgResynchInfoDt& right) {
    if (left.rand == right.rand && left.auts == right.auts) {
        return true;
    }
    else {
        return false;
    }
}

inline bool operator!=(const HSS_AvgResynchInfoDt& left, const HSS_AvgResynchInfoDt& right) {
    if (!(left == right)) {
        return true;
    }
    else {
        return false;
    }
}

#endif
