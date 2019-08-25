
#ifndef RANDOMDISTRIBUTION_CATAGORY
#define RANDOMDISTRIBUTION_CATAGORY

namespace RandomDistribution
{


template <typename CatagoryEnum>
class Catagory
{
public:
    Catagory() = delete;
    Catagory(const CatagoryEnum& catagory, int weight = 1) :
        m_catagory{catagory}, m_weight{weight} {}

    inline const CatagoryEnum& catagory() const { return m_catagory; }
    inline int weight() const { return m_weight; }
    inline void setWeight(int weight) { m_weight = weight; }

private:
    CatagoryEnum m_catagory {0};
    int m_weight {0};
};

template <typename CatagoryEnum>
inline bool operator==(const Catagory<CatagoryEnum>& lhs, const Catagory<CatagoryEnum>& rhs)
{
    return lhs.m_catagory == rhs.m_catagory;
} 


}

#endif // RANDOMDISTRIBUTION_CATAGORY

