#ifndef HSS_AvgUserIdTypeDt_h
#define HSS_AvgUserIdTypeDt_h

class HSS_AvgUserIdTypeDt {
public:
    enum HSS_AvgUserIdTypeDt_INTERNAL {
        isimE,
        usimE
    };

    int ordinal;
    
    HSS_AvgUserIdTypeDt (HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL value): ordinal(value) {};
    HSS_AvgUserIdTypeDt (const HSS_AvgUserIdTypeDt& r): ordinal(r.ordinal) {};
    HSS_AvgUserIdTypeDt (): ordinal(0) {};
    
    ~HSS_AvgUserIdTypeDt () {};
    
    const HSS_AvgUserIdTypeDt& operator= (const HSS_AvgUserIdTypeDt&);
    operator HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL () const;

    friend bool operator== (const HSS_AvgUserIdTypeDt& l, const HSS_AvgUserIdTypeDt& r);
    friend bool operator== (const HSS_AvgUserIdTypeDt& l, HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL r);
    friend bool operator== (HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL l, const HSS_AvgUserIdTypeDt& r);
    
    friend bool operator!= (const HSS_AvgUserIdTypeDt& l, const HSS_AvgUserIdTypeDt& r);
    friend bool operator!= (const HSS_AvgUserIdTypeDt& l, HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL r);
    friend bool operator!= (HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL l, const HSS_AvgUserIdTypeDt& r);
    
    friend bool operator<  (const HSS_AvgUserIdTypeDt& l, const HSS_AvgUserIdTypeDt& r);
    friend bool operator<  (const HSS_AvgUserIdTypeDt& l, HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL r);
    friend bool operator<  (HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL l, const HSS_AvgUserIdTypeDt& r);
    friend bool operator<= (const HSS_AvgUserIdTypeDt& l, const HSS_AvgUserIdTypeDt& r);
    friend bool operator<= (const HSS_AvgUserIdTypeDt& l, HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL r);
    friend bool operator<= (HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL l, const HSS_AvgUserIdTypeDt& r);
    
    friend bool operator>  (const HSS_AvgUserIdTypeDt& l, const HSS_AvgUserIdTypeDt& r);
    friend bool operator>  (const HSS_AvgUserIdTypeDt& l, HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL r);
    friend bool operator>  (HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL l, const HSS_AvgUserIdTypeDt& r);
    friend bool operator>= (const HSS_AvgUserIdTypeDt& l, const HSS_AvgUserIdTypeDt& r);
    friend bool operator>= (const HSS_AvgUserIdTypeDt& l, HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL r);
    friend bool operator>= (HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL l, const HSS_AvgUserIdTypeDt& r);
};

inline HSS_AvgUserIdTypeDt::operator HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL () const {
    return (HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL) this->ordinal;
}

inline const HSS_AvgUserIdTypeDt& HSS_AvgUserIdTypeDt::operator= (const HSS_AvgUserIdTypeDt& r) {
    this->ordinal = r.ordinal;
    return *this;
}

inline bool operator== (const HSS_AvgUserIdTypeDt& l, const HSS_AvgUserIdTypeDt& r) {
    return l.ordinal == r.ordinal;
}

inline bool operator== (const HSS_AvgUserIdTypeDt& l, HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL r) {
    return l.ordinal == r;
}

inline bool operator== (HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL l, const HSS_AvgUserIdTypeDt& r) {
    return l == r.ordinal;
}

inline bool operator!= (const HSS_AvgUserIdTypeDt& l, const HSS_AvgUserIdTypeDt& r) {
    return l.ordinal != r.ordinal;
}

inline bool operator!= (const HSS_AvgUserIdTypeDt& l, HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL r) {
    return l.ordinal != r;
}

inline bool operator!= (HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL l, const HSS_AvgUserIdTypeDt& r) {
    return l != r.ordinal;
}

inline bool operator< (const HSS_AvgUserIdTypeDt& l, const HSS_AvgUserIdTypeDt& r) {
    return l.ordinal < r.ordinal;
}

inline bool operator< (const HSS_AvgUserIdTypeDt& l, HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL r) {
    return l.ordinal < r;
}

inline bool operator< (HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL l, const HSS_AvgUserIdTypeDt& r) {
    return l < r.ordinal;
}

inline bool operator<= (const HSS_AvgUserIdTypeDt& l, const HSS_AvgUserIdTypeDt& r) {
    return l.ordinal <= r.ordinal;
}

inline bool operator<= (const HSS_AvgUserIdTypeDt& l, HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL r) {
    return l.ordinal <= r;
}

inline bool operator<= (HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL l, const HSS_AvgUserIdTypeDt& r) {
    return l <= r.ordinal;
}

inline bool operator> (const HSS_AvgUserIdTypeDt& l, const HSS_AvgUserIdTypeDt& r) {
    return l.ordinal > r.ordinal;
}

inline bool operator> (const HSS_AvgUserIdTypeDt& l, HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL r) {
    return l.ordinal > r;
}

inline bool operator> (HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL l, const HSS_AvgUserIdTypeDt& r) {
    return l > r.ordinal;
}

inline bool operator>= (const HSS_AvgUserIdTypeDt& l, const HSS_AvgUserIdTypeDt& r) {
    return l.ordinal >= r.ordinal;
}

inline bool operator>= (const HSS_AvgUserIdTypeDt& l, HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL r) {
    return l.ordinal >= r;
}

inline bool operator>= (HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL l, const HSS_AvgUserIdTypeDt& r) {
    return l >= r.ordinal;
}

#endif
