
// #include "gtest/gtest.h"
// #include "CatagoricalDistribution.hpp"
// #include <iostream>

// TEST(Dist, SanittyCheck)
// {
//     enum class Catagories
//     {
//         Apple,
//         Orange,
//         Banana,
//         Kiwi,
//         Grape
//     };

//     RandomDistribution::CatagoricalDistribution<Catagories> dist{Catagories::Apple};
//     dist.update(Catagories::Orange);
//     dist.update(Catagories::Banana);
//     dist.update(Catagories::Kiwi);
//     dist.update(Catagories::Grape);

//     for (int i = 0; i < 10; ++i)
//     {
//         switch (dist.generate())
//         {
//             case Catagories::Apple:
//                 std::cout << "Apple";
//                 break;
//             case Catagories::Orange:
//                 std::cout << "Orange";
//                 break;
//             case Catagories::Banana:
//                 std::cout << "Banana";
//                 break;
//             case Catagories::Kiwi:
//                 std::cout << "Kiwi";
//                 break;
//             case Catagories::Grape:
//                 std::cout << "Grape";
//                 break;
//             default:
//                 std::cout << "Unknown";
//                 break;
//         }
//         std::cout << "\n";
//     }
// }