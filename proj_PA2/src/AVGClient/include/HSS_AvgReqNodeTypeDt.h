#ifndef HSS_AvgReqNodeTypeDt_h
#define HSS_AvgReqNodeTypeDt_h

class HSS_AvgReqNodeTypeDt {
public:
    enum HSS_AvgReqNodeTypeDt_INTERNAL {
        cscfE,
        mmeE,
        aaaE,
        bsfE,
        epsAaaE
    };

    int ordinal;

    HSS_AvgReqNodeTypeDt (HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL value): ordinal(value) {};
    HSS_AvgReqNodeTypeDt (const HSS_AvgReqNodeTypeDt& r): ordinal(r.ordinal) {};
    HSS_AvgReqNodeTypeDt () {};

    ~HSS_AvgReqNodeTypeDt () {};
    
    const HSS_AvgReqNodeTypeDt& operator= (const HSS_AvgReqNodeTypeDt&);
    operator HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL () const;
    
    friend bool operator== (const HSS_AvgReqNodeTypeDt& l, const HSS_AvgReqNodeTypeDt& r);
    friend bool operator== (const HSS_AvgReqNodeTypeDt& l, HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL r);
    friend bool operator== (HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL l, const HSS_AvgReqNodeTypeDt& r);
    
    friend bool operator!= (const HSS_AvgReqNodeTypeDt& l, const HSS_AvgReqNodeTypeDt& r);
    friend bool operator!= (const HSS_AvgReqNodeTypeDt& l, HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL r);
    friend bool operator!= (HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL l, const HSS_AvgReqNodeTypeDt& r);
    
    friend bool operator<  (const HSS_AvgReqNodeTypeDt& l, const HSS_AvgReqNodeTypeDt& r);
    friend bool operator<  (const HSS_AvgReqNodeTypeDt& l, HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL r);
    friend bool operator<  (HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL l, const HSS_AvgReqNodeTypeDt& r);
    friend bool operator<= (const HSS_AvgReqNodeTypeDt& l, const HSS_AvgReqNodeTypeDt& r);
    friend bool operator<= (const HSS_AvgReqNodeTypeDt& l, HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL r);
    friend bool operator<= (HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL l, const HSS_AvgReqNodeTypeDt& r);
    
    friend bool operator>  (const HSS_AvgReqNodeTypeDt& l, const HSS_AvgReqNodeTypeDt& r);
    friend bool operator>  (const HSS_AvgReqNodeTypeDt& l, HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL r);
    friend bool operator>  (HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL l, const HSS_AvgReqNodeTypeDt& r);
    friend bool operator>= (const HSS_AvgReqNodeTypeDt& l, const HSS_AvgReqNodeTypeDt& r);
    friend bool operator>= (const HSS_AvgReqNodeTypeDt& l, HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL r);
    friend bool operator>= (HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL l, const HSS_AvgReqNodeTypeDt& r);
};


inline HSS_AvgReqNodeTypeDt::operator HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL () const {
    return (HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL) this->ordinal;
}

inline const HSS_AvgReqNodeTypeDt& HSS_AvgReqNodeTypeDt::operator= (const HSS_AvgReqNodeTypeDt& r) {
    this->ordinal = r.ordinal;
    return *this;
}


inline bool operator== (const HSS_AvgReqNodeTypeDt& l, const HSS_AvgReqNodeTypeDt& r) {
    return l.ordinal == r.ordinal;
}

inline bool operator== (const HSS_AvgReqNodeTypeDt& l, HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL r) {
    return l.ordinal == r;
}

inline bool operator== (HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL l, const HSS_AvgReqNodeTypeDt& r) {
    return l == r.ordinal;
}

inline bool operator!= (const HSS_AvgReqNodeTypeDt& l, const HSS_AvgReqNodeTypeDt& r) {
    return l.ordinal != r.ordinal;
}

inline bool operator!= (const HSS_AvgReqNodeTypeDt& l, HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL r) {
    return l.ordinal != r;
}

inline bool operator!= (HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL l, const HSS_AvgReqNodeTypeDt& r) {
    return l != r.ordinal;
}

inline bool operator< (const HSS_AvgReqNodeTypeDt& l, const HSS_AvgReqNodeTypeDt& r) {
    return l.ordinal < r.ordinal;
}

inline bool operator< (const HSS_AvgReqNodeTypeDt& l, HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL r) {
    return l.ordinal < r;
}

inline bool operator< (HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL l, const HSS_AvgReqNodeTypeDt& r) {
    return l < r.ordinal;
}

inline bool operator<= (const HSS_AvgReqNodeTypeDt& l, const HSS_AvgReqNodeTypeDt& r) {
    return l.ordinal <= r.ordinal;
}

inline bool operator<= (const HSS_AvgReqNodeTypeDt& l, HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL r) {
    return l.ordinal <= r;
}

inline bool operator<= (HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL l, const HSS_AvgReqNodeTypeDt& r) {
    return l <= r.ordinal;
}

inline bool operator> (const HSS_AvgReqNodeTypeDt& l, const HSS_AvgReqNodeTypeDt& r) {
    return l.ordinal > r.ordinal;
}

inline bool operator> (const HSS_AvgReqNodeTypeDt& l, HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL r) {
    return l.ordinal > r;
}

inline bool operator> (HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL l, const HSS_AvgReqNodeTypeDt& r) {
    return l > r.ordinal;
}

inline bool operator>= (const HSS_AvgReqNodeTypeDt& l, const HSS_AvgReqNodeTypeDt& r) {
    return l.ordinal >= r.ordinal;
}

inline bool operator>= (const HSS_AvgReqNodeTypeDt& l, HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL r) {
    return l.ordinal >= r;
}

inline bool operator>= (HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL l, const HSS_AvgReqNodeTypeDt& r) {
    return l >= r.ordinal;
}

#endif
