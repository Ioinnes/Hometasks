#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <list>
#include <forward_list>
#include <deque>
int main() {

    std::vector<int>  vector1{471, 650, 798, 830, 941, 729, 441, 544, 181, 189, 479, 932, 570, 469, 59, 663, 163, 461, 362, 295, 730, 394, 788, 639, 361, 445, 141, 233, 565, 37, 767, 195, 249, 321, 128, 804, 363, 523, 828, 260, 452, 125, 156, 634, 318, 916, 946, 710, 628, 698, 413, 949, 701, 19, 133, 942, 545, 170, 195, 757, 56, 475, 711, 619, 495, 962, 431, 434, 219, 513, 647, 792, 590, 316, 238, 816, 898, 107, 733, 216, 96, 688, 389, 767, 439, 648, 825, 562, 204, 309, 307, 1, 677, 237, 560, 458, 270, 881, 799, 521, 703, 464, 212, 244, 617, 435, 817, 764, 567, 427, 540, 310, 322, 453, 336, 349, 603, 106, 575, 968, 164, 781, 719, 79, 285, 642, 951, 733, 5, 457, 821, 451, 733, 251, 108, 320, 543, 84, 110, 280, 68, 523, 367, 575, 898, 232, 995, 75, 870, 46, 447, 294, 711, 175, 197, 81, 119, 614, 936, 705, 611, 693, 670, 588, 676, 232, 118, 378, 680, 115, 961, 326, 555, 57, 918, 30, 471, 393, 976, 491, 982, 71, 607, 461, 231, 493, 548, 389, 220, 483, 215, 925, 758, 291, 83, 395, 528, 637, 930, 904, 14, 363, 599, 510, 12, 812, 349, 794, 810, 932, 614, 527, 967, 121, 884, 481, 291, 662, 659, 488, 773, 854, 650, 752, 909, 555, 27, 92, 621, 790, 369, 435, 200, 45, 534, 694, 185, 545, 102, 270, 592, 978, 792, 482, 561, 892, 377, 528, 556, 68, 778, 278, 256, 898, 802, 710, 35, 956, 854, 295, 834, 687, 322, 334, 944, 943, 198, 640, 481, 647, 635, 961, 548, 914, 785, 769, 952, 965, 357, 62, 829, 924, 28, 733, 549, 276, 570, 789, 105, 215, 801, 785, 1000, 27, 532, 888, 674, 833, 109, 533, 899, 101, 289, 175, 158, 530, 58, 523, 569, 315, 660, 744, 891, 7, 927, 94, 518, 456, 547, 280, 313, 96, 587, 175, 367, 700, 304, 503, 72, 719, 596, 514, 226, 310, 480, 551, 379, 511, 610, 732, 203, 358, 282, 528, 712, 26, 140, 990, 843, 281, 809, 121, 678, 775, 361, 39, 283, 934, 980, 983, 405, 920, 554, 630, 252, 575, 282, 294, 514, 442, 735, 644, 338, 754, 425, 468, 10, 701, 689, 32, 507, 408, 930, 545, 416, 306, 38, 335, 268, 567, 633, 504, 462, 913, 843, 170, 913, 821, 524, 906, 882, 289, 49, 521, 756, 343, 822, 98, 888, 45, 921, 20, 646, 142, 297, 828, 629, 337, 996, 440, 163, 198, 259, 629, 823, 400, 851, 621, 56, 639, 400, 112, 363, 675, 879, 243, 465, 627, 10, 319, 825, 572, 26, 495, 797, 52, 185, 58, 423, 427, 424, 390, 121, 109, 816, 565, 919, 203, 807, 750, 550, 58, 873, 925, 175, 470, 28, 448, 844, 726, 30, 915, 954, 313, 770, 347, 473, 509, 662, 192, 93, 967, 733, 632, 257, 579, 835, 766, 28, 943, 144, 393, 208, 454, 5, 508, 326, 375, 117, 142, 494, 21, 610, 88, 680, 558, 475, 396, 321, 371, 125, 869, 576, 364, 709, 141, 599, 240, 848, 880, 462, 90, 238, 568, 190, 624, 936, 873, 707, 395, 129, 634, 38, 21, 851, 326, 566, 421, 532, 413, 75, 775, 432, 822, 475, 555, 960, 139, 243, 261, 660, 996, 344, 644, 322, 835, 185, 206, 44, 101, 586, 356, 92, 767, 645, 523, 98, 241, 431, 452, 3, 871, 557, 43, 750, 505, 813, 123, 478, 28, 281, 727, 194, 325, 860, 206, 961, 210, 473, 827, 703, 826, 637, 491, 91, 697, 63, 515, 447, 953, 765, 657, 319, 48, 276, 464, 667, 372, 960, 114, 175, 910, 998, 835, 534, 840, 896, 132, 286, 144, 426, 956, 922, 241, 622, 370, 931, 423, 559, 78, 26, 784, 460, 967, 324, 890, 823, 620, 903, 364, 540, 506, 790, 880, 221, 312, 289, 291, 36, 48, 268, 212, 231, 958, 260, 400, 297, 20, 182, 110, 675, 798, 825, 701, 286, 941, 123, 324, 657, 393, 790, 358, 564, 185, 949, 330, 520, 979, 654, 433, 947, 44, 767, 654, 327, 434, 275, 938, 754, 569, 165, 329, 856, 320, 253, 783, 1000, 991, 690, 255, 864, 583, 241, 868, 543, 215, 845, 750, 943, 237, 213, 159, 948, 861, 918, 974, 892, 883, 563, 932, 49, 448, 990, 932, 176, 234, 575, 45, 117, 557, 225, 507, 158, 897, 488, 433, 420, 746, 551, 861, 437, 96, 185, 980, 394, 467, 295, 816, 123, 66, 965, 135, 226, 449, 851, 337, 123, 571, 483, 306, 249, 505, 562, 556, 823, 81, 246, 624, 545, 308, 327, 390, 861, 980, 119, 520, 310, 861, 477, 265, 640, 42, 126, 94, 115, 72, 89, 291, 604, 708, 342, 754, 508, 622, 886, 878, 501, 403, 806, 793, 940, 13, 382, 528, 454, 736, 368, 572, 444, 179, 512, 709, 488, 555, 294, 874, 452, 465, 434, 825, 901, 759, 835, 316, 675, 275, 488, 19, 12, 71, 157, 652, 937, 564, 405, 564, 247, 568, 180, 632, 513, 459, 278, 76, 188, 899, 393, 47, 621, 311, 391, 420, 580, 891, 826, 31, 918, 593, 807, 601, 537, 926, 176, 726, 143, 821, 195, 321, 651, 384, 8, 218, 86, 995, 104, 344, 943, 229, 928, 524, 99, 74, 337, 649, 54, 603, 818, 428, 604, 650, 6, 800, 582, 41, 765, 390, 57, 282, 955, 375, 67, 545, 402, 926, 587, 805, 939, 152, 155, 288, 30, 993, 192, 59, 180, 425, 332, 237, 770, 841, 509, 95, 525, 849, 765, 631, 337, 78, 590, 650, 36, 890, 787, 497, 456, 766, 223, 59, 976, 917, 258, 894, 14, 677, 41, 848, 846, 279, 31, 107, 699, 492, 127, 537, 744, 687, 683, 951, 240, 296, 130, 342, 835, 796, 27, 149, 300, 656, 94, 998, 14, 841, 682, 324, 597, 76, 365, 14, 77, 861, 522, 237, 647, 162, 109, 1, 153, 584, 177, 31, 202, 22, 589, 780, 97, 706, 814, 142, 228, 189};

    auto begin = std::chrono::steady_clock::now();
    std::sort(vector1.begin(), vector1.end());
    auto end = std::chrono::steady_clock::now();
    auto sortTime = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    std::cout << "The vector std::sort time: " << sortTime.count() << " mis\n";

    int array[1000] = {471, 650, 798, 830, 941, 729, 441, 544, 181, 189, 479, 932, 570, 469, 59, 663, 163, 461, 362, 295, 730, 394, 788, 639, 361, 445, 141, 233, 565, 37, 767, 195, 249, 321, 128, 804, 363, 523, 828, 260, 452, 125, 156, 634, 318, 916, 946, 710, 628, 698, 413, 949, 701, 19, 133, 942, 545, 170, 195, 757, 56, 475, 711, 619, 495, 962, 431, 434, 219, 513, 647, 792, 590, 316, 238, 816, 898, 107, 733, 216, 96, 688, 389, 767, 439, 648, 825, 562, 204, 309, 307, 1, 677, 237, 560, 458, 270, 881, 799, 521, 703, 464, 212, 244, 617, 435, 817, 764, 567, 427, 540, 310, 322, 453, 336, 349, 603, 106, 575, 968, 164, 781, 719, 79, 285, 642, 951, 733, 5, 457, 821, 451, 733, 251, 108, 320, 543, 84, 110, 280, 68, 523, 367, 575, 898, 232, 995, 75, 870, 46, 447, 294, 711, 175, 197, 81, 119, 614, 936, 705, 611, 693, 670, 588, 676, 232, 118, 378, 680, 115, 961, 326, 555, 57, 918, 30, 471, 393, 976, 491, 982, 71, 607, 461, 231, 493, 548, 389, 220, 483, 215, 925, 758, 291, 83, 395, 528, 637, 930, 904, 14, 363, 599, 510, 12, 812, 349, 794, 810, 932, 614, 527, 967, 121, 884, 481, 291, 662, 659, 488, 773, 854, 650, 752, 909, 555, 27, 92, 621, 790, 369, 435, 200, 45, 534, 694, 185, 545, 102, 270, 592, 978, 792, 482, 561, 892, 377, 528, 556, 68, 778, 278, 256, 898, 802, 710, 35, 956, 854, 295, 834, 687, 322, 334, 944, 943, 198, 640, 481, 647, 635, 961, 548, 914, 785, 769, 952, 965, 357, 62, 829, 924, 28, 733, 549, 276, 570, 789, 105, 215, 801, 785, 1000, 27, 532, 888, 674, 833, 109, 533, 899, 101, 289, 175, 158, 530, 58, 523, 569, 315, 660, 744, 891, 7, 927, 94, 518, 456, 547, 280, 313, 96, 587, 175, 367, 700, 304, 503, 72, 719, 596, 514, 226, 310, 480, 551, 379, 511, 610, 732, 203, 358, 282, 528, 712, 26, 140, 990, 843, 281, 809, 121, 678, 775, 361, 39, 283, 934, 980, 983, 405, 920, 554, 630, 252, 575, 282, 294, 514, 442, 735, 644, 338, 754, 425, 468, 10, 701, 689, 32, 507, 408, 930, 545, 416, 306, 38, 335, 268, 567, 633, 504, 462, 913, 843, 170, 913, 821, 524, 906, 882, 289, 49, 521, 756, 343, 822, 98, 888, 45, 921, 20, 646, 142, 297, 828, 629, 337, 996, 440, 163, 198, 259, 629, 823, 400, 851, 621, 56, 639, 400, 112, 363, 675, 879, 243, 465, 627, 10, 319, 825, 572, 26, 495, 797, 52, 185, 58, 423, 427, 424, 390, 121, 109, 816, 565, 919, 203, 807, 750, 550, 58, 873, 925, 175, 470, 28, 448, 844, 726, 30, 915, 954, 313, 770, 347, 473, 509, 662, 192, 93, 967, 733, 632, 257, 579, 835, 766, 28, 943, 144, 393, 208, 454, 5, 508, 326, 375, 117, 142, 494, 21, 610, 88, 680, 558, 475, 396, 321, 371, 125, 869, 576, 364, 709, 141, 599, 240, 848, 880, 462, 90, 238, 568, 190, 624, 936, 873, 707, 395, 129, 634, 38, 21, 851, 326, 566, 421, 532, 413, 75, 775, 432, 822, 475, 555, 960, 139, 243, 261, 660, 996, 344, 644, 322, 835, 185, 206, 44, 101, 586, 356, 92, 767, 645, 523, 98, 241, 431, 452, 3, 871, 557, 43, 750, 505, 813, 123, 478, 28, 281, 727, 194, 325, 860, 206, 961, 210, 473, 827, 703, 826, 637, 491, 91, 697, 63, 515, 447, 953, 765, 657, 319, 48, 276, 464, 667, 372, 960, 114, 175, 910, 998, 835, 534, 840, 896, 132, 286, 144, 426, 956, 922, 241, 622, 370, 931, 423, 559, 78, 26, 784, 460, 967, 324, 890, 823, 620, 903, 364, 540, 506, 790, 880, 221, 312, 289, 291, 36, 48, 268, 212, 231, 958, 260, 400, 297, 20, 182, 110, 675, 798, 825, 701, 286, 941, 123, 324, 657, 393, 790, 358, 564, 185, 949, 330, 520, 979, 654, 433, 947, 44, 767, 654, 327, 434, 275, 938, 754, 569, 165, 329, 856, 320, 253, 783, 1000, 991, 690, 255, 864, 583, 241, 868, 543, 215, 845, 750, 943, 237, 213, 159, 948, 861, 918, 974, 892, 883, 563, 932, 49, 448, 990, 932, 176, 234, 575, 45, 117, 557, 225, 507, 158, 897, 488, 433, 420, 746, 551, 861, 437, 96, 185, 980, 394, 467, 295, 816, 123, 66, 965, 135, 226, 449, 851, 337, 123, 571, 483, 306, 249, 505, 562, 556, 823, 81, 246, 624, 545, 308, 327, 390, 861, 980, 119, 520, 310, 861, 477, 265, 640, 42, 126, 94, 115, 72, 89, 291, 604, 708, 342, 754, 508, 622, 886, 878, 501, 403, 806, 793, 940, 13, 382, 528, 454, 736, 368, 572, 444, 179, 512, 709, 488, 555, 294, 874, 452, 465, 434, 825, 901, 759, 835, 316, 675, 275, 488, 19, 12, 71, 157, 652, 937, 564, 405, 564, 247, 568, 180, 632, 513, 459, 278, 76, 188, 899, 393, 47, 621, 311, 391, 420, 580, 891, 826, 31, 918, 593, 807, 601, 537, 926, 176, 726, 143, 821, 195, 321, 651, 384, 8, 218, 86, 995, 104, 344, 943, 229, 928, 524, 99, 74, 337, 649, 54, 603, 818, 428, 604, 650, 6, 800, 582, 41, 765, 390, 57, 282, 955, 375, 67, 545, 402, 926, 587, 805, 939, 152, 155, 288, 30, 993, 192, 59, 180, 425, 332, 237, 770, 841, 509, 95, 525, 849, 765, 631, 337, 78, 590, 650, 36, 890, 787, 497, 456, 766, 223, 59, 976, 917, 258, 894, 14, 677, 41, 848, 846, 279, 31, 107, 699, 492, 127, 537, 744, 687, 683, 951, 240, 296, 130, 342, 835, 796, 27, 149, 300, 656, 94, 998, 14, 841, 682, 324, 597, 76, 365, 14, 77, 861, 522, 237, 647, 162, 109, 1, 153, 584, 177, 31, 202, 22, 589, 780, 97, 706, 814, 142, 228, 189};

    begin = std::chrono::steady_clock::now();
    std::sort(array, array+1000);
    end = std::chrono::steady_clock::now();
    sortTime = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    std::cout << "The array std::sort time: " << sortTime.count() << " mis\n";

    std::deque<int> deque = {471, 650, 798, 830, 941, 729, 441, 544, 181, 189, 479, 932, 570, 469, 59, 663, 163, 461, 362, 295, 730, 394, 788, 639, 361, 445, 141, 233, 565, 37, 767, 195, 249, 321, 128, 804, 363, 523, 828, 260, 452, 125, 156, 634, 318, 916, 946, 710, 628, 698, 413, 949, 701, 19, 133, 942, 545, 170, 195, 757, 56, 475, 711, 619, 495, 962, 431, 434, 219, 513, 647, 792, 590, 316, 238, 816, 898, 107, 733, 216, 96, 688, 389, 767, 439, 648, 825, 562, 204, 309, 307, 1, 677, 237, 560, 458, 270, 881, 799, 521, 703, 464, 212, 244, 617, 435, 817, 764, 567, 427, 540, 310, 322, 453, 336, 349, 603, 106, 575, 968, 164, 781, 719, 79, 285, 642, 951, 733, 5, 457, 821, 451, 733, 251, 108, 320, 543, 84, 110, 280, 68, 523, 367, 575, 898, 232, 995, 75, 870, 46, 447, 294, 711, 175, 197, 81, 119, 614, 936, 705, 611, 693, 670, 588, 676, 232, 118, 378, 680, 115, 961, 326, 555, 57, 918, 30, 471, 393, 976, 491, 982, 71, 607, 461, 231, 493, 548, 389, 220, 483, 215, 925, 758, 291, 83, 395, 528, 637, 930, 904, 14, 363, 599, 510, 12, 812, 349, 794, 810, 932, 614, 527, 967, 121, 884, 481, 291, 662, 659, 488, 773, 854, 650, 752, 909, 555, 27, 92, 621, 790, 369, 435, 200, 45, 534, 694, 185, 545, 102, 270, 592, 978, 792, 482, 561, 892, 377, 528, 556, 68, 778, 278, 256, 898, 802, 710, 35, 956, 854, 295, 834, 687, 322, 334, 944, 943, 198, 640, 481, 647, 635, 961, 548, 914, 785, 769, 952, 965, 357, 62, 829, 924, 28, 733, 549, 276, 570, 789, 105, 215, 801, 785, 1000, 27, 532, 888, 674, 833, 109, 533, 899, 101, 289, 175, 158, 530, 58, 523, 569, 315, 660, 744, 891, 7, 927, 94, 518, 456, 547, 280, 313, 96, 587, 175, 367, 700, 304, 503, 72, 719, 596, 514, 226, 310, 480, 551, 379, 511, 610, 732, 203, 358, 282, 528, 712, 26, 140, 990, 843, 281, 809, 121, 678, 775, 361, 39, 283, 934, 980, 983, 405, 920, 554, 630, 252, 575, 282, 294, 514, 442, 735, 644, 338, 754, 425, 468, 10, 701, 689, 32, 507, 408, 930, 545, 416, 306, 38, 335, 268, 567, 633, 504, 462, 913, 843, 170, 913, 821, 524, 906, 882, 289, 49, 521, 756, 343, 822, 98, 888, 45, 921, 20, 646, 142, 297, 828, 629, 337, 996, 440, 163, 198, 259, 629, 823, 400, 851, 621, 56, 639, 400, 112, 363, 675, 879, 243, 465, 627, 10, 319, 825, 572, 26, 495, 797, 52, 185, 58, 423, 427, 424, 390, 121, 109, 816, 565, 919, 203, 807, 750, 550, 58, 873, 925, 175, 470, 28, 448, 844, 726, 30, 915, 954, 313, 770, 347, 473, 509, 662, 192, 93, 967, 733, 632, 257, 579, 835, 766, 28, 943, 144, 393, 208, 454, 5, 508, 326, 375, 117, 142, 494, 21, 610, 88, 680, 558, 475, 396, 321, 371, 125, 869, 576, 364, 709, 141, 599, 240, 848, 880, 462, 90, 238, 568, 190, 624, 936, 873, 707, 395, 129, 634, 38, 21, 851, 326, 566, 421, 532, 413, 75, 775, 432, 822, 475, 555, 960, 139, 243, 261, 660, 996, 344, 644, 322, 835, 185, 206, 44, 101, 586, 356, 92, 767, 645, 523, 98, 241, 431, 452, 3, 871, 557, 43, 750, 505, 813, 123, 478, 28, 281, 727, 194, 325, 860, 206, 961, 210, 473, 827, 703, 826, 637, 491, 91, 697, 63, 515, 447, 953, 765, 657, 319, 48, 276, 464, 667, 372, 960, 114, 175, 910, 998, 835, 534, 840, 896, 132, 286, 144, 426, 956, 922, 241, 622, 370, 931, 423, 559, 78, 26, 784, 460, 967, 324, 890, 823, 620, 903, 364, 540, 506, 790, 880, 221, 312, 289, 291, 36, 48, 268, 212, 231, 958, 260, 400, 297, 20, 182, 110, 675, 798, 825, 701, 286, 941, 123, 324, 657, 393, 790, 358, 564, 185, 949, 330, 520, 979, 654, 433, 947, 44, 767, 654, 327, 434, 275, 938, 754, 569, 165, 329, 856, 320, 253, 783, 1000, 991, 690, 255, 864, 583, 241, 868, 543, 215, 845, 750, 943, 237, 213, 159, 948, 861, 918, 974, 892, 883, 563, 932, 49, 448, 990, 932, 176, 234, 575, 45, 117, 557, 225, 507, 158, 897, 488, 433, 420, 746, 551, 861, 437, 96, 185, 980, 394, 467, 295, 816, 123, 66, 965, 135, 226, 449, 851, 337, 123, 571, 483, 306, 249, 505, 562, 556, 823, 81, 246, 624, 545, 308, 327, 390, 861, 980, 119, 520, 310, 861, 477, 265, 640, 42, 126, 94, 115, 72, 89, 291, 604, 708, 342, 754, 508, 622, 886, 878, 501, 403, 806, 793, 940, 13, 382, 528, 454, 736, 368, 572, 444, 179, 512, 709, 488, 555, 294, 874, 452, 465, 434, 825, 901, 759, 835, 316, 675, 275, 488, 19, 12, 71, 157, 652, 937, 564, 405, 564, 247, 568, 180, 632, 513, 459, 278, 76, 188, 899, 393, 47, 621, 311, 391, 420, 580, 891, 826, 31, 918, 593, 807, 601, 537, 926, 176, 726, 143, 821, 195, 321, 651, 384, 8, 218, 86, 995, 104, 344, 943, 229, 928, 524, 99, 74, 337, 649, 54, 603, 818, 428, 604, 650, 6, 800, 582, 41, 765, 390, 57, 282, 955, 375, 67, 545, 402, 926, 587, 805, 939, 152, 155, 288, 30, 993, 192, 59, 180, 425, 332, 237, 770, 841, 509, 95, 525, 849, 765, 631, 337, 78, 590, 650, 36, 890, 787, 497, 456, 766, 223, 59, 976, 917, 258, 894, 14, 677, 41, 848, 846, 279, 31, 107, 699, 492, 127, 537, 744, 687, 683, 951, 240, 296, 130, 342, 835, 796, 27, 149, 300, 656, 94, 998, 14, 841, 682, 324, 597, 76, 365, 14, 77, 861, 522, 237, 647, 162, 109, 1, 153, 584, 177, 31, 202, 22, 589, 780, 97, 706, 814, 142, 228, 189};
    begin = std::chrono::steady_clock::now();
    std::sort(deque.begin(), deque.end());
    end = std::chrono::steady_clock::now();
    sortTime = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    std::cout << "The deque std::sort time: " << sortTime.count() << " mis\n";

    std::list<int> list = {471, 650, 798, 830, 941, 729, 441, 544, 181, 189, 479, 932, 570, 469, 59, 663, 163, 461, 362, 295, 730, 394, 788, 639, 361, 445, 141, 233, 565, 37, 767, 195, 249, 321, 128, 804, 363, 523, 828, 260, 452, 125, 156, 634, 318, 916, 946, 710, 628, 698, 413, 949, 701, 19, 133, 942, 545, 170, 195, 757, 56, 475, 711, 619, 495, 962, 431, 434, 219, 513, 647, 792, 590, 316, 238, 816, 898, 107, 733, 216, 96, 688, 389, 767, 439, 648, 825, 562, 204, 309, 307, 1, 677, 237, 560, 458, 270, 881, 799, 521, 703, 464, 212, 244, 617, 435, 817, 764, 567, 427, 540, 310, 322, 453, 336, 349, 603, 106, 575, 968, 164, 781, 719, 79, 285, 642, 951, 733, 5, 457, 821, 451, 733, 251, 108, 320, 543, 84, 110, 280, 68, 523, 367, 575, 898, 232, 995, 75, 870, 46, 447, 294, 711, 175, 197, 81, 119, 614, 936, 705, 611, 693, 670, 588, 676, 232, 118, 378, 680, 115, 961, 326, 555, 57, 918, 30, 471, 393, 976, 491, 982, 71, 607, 461, 231, 493, 548, 389, 220, 483, 215, 925, 758, 291, 83, 395, 528, 637, 930, 904, 14, 363, 599, 510, 12, 812, 349, 794, 810, 932, 614, 527, 967, 121, 884, 481, 291, 662, 659, 488, 773, 854, 650, 752, 909, 555, 27, 92, 621, 790, 369, 435, 200, 45, 534, 694, 185, 545, 102, 270, 592, 978, 792, 482, 561, 892, 377, 528, 556, 68, 778, 278, 256, 898, 802, 710, 35, 956, 854, 295, 834, 687, 322, 334, 944, 943, 198, 640, 481, 647, 635, 961, 548, 914, 785, 769, 952, 965, 357, 62, 829, 924, 28, 733, 549, 276, 570, 789, 105, 215, 801, 785, 1000, 27, 532, 888, 674, 833, 109, 533, 899, 101, 289, 175, 158, 530, 58, 523, 569, 315, 660, 744, 891, 7, 927, 94, 518, 456, 547, 280, 313, 96, 587, 175, 367, 700, 304, 503, 72, 719, 596, 514, 226, 310, 480, 551, 379, 511, 610, 732, 203, 358, 282, 528, 712, 26, 140, 990, 843, 281, 809, 121, 678, 775, 361, 39, 283, 934, 980, 983, 405, 920, 554, 630, 252, 575, 282, 294, 514, 442, 735, 644, 338, 754, 425, 468, 10, 701, 689, 32, 507, 408, 930, 545, 416, 306, 38, 335, 268, 567, 633, 504, 462, 913, 843, 170, 913, 821, 524, 906, 882, 289, 49, 521, 756, 343, 822, 98, 888, 45, 921, 20, 646, 142, 297, 828, 629, 337, 996, 440, 163, 198, 259, 629, 823, 400, 851, 621, 56, 639, 400, 112, 363, 675, 879, 243, 465, 627, 10, 319, 825, 572, 26, 495, 797, 52, 185, 58, 423, 427, 424, 390, 121, 109, 816, 565, 919, 203, 807, 750, 550, 58, 873, 925, 175, 470, 28, 448, 844, 726, 30, 915, 954, 313, 770, 347, 473, 509, 662, 192, 93, 967, 733, 632, 257, 579, 835, 766, 28, 943, 144, 393, 208, 454, 5, 508, 326, 375, 117, 142, 494, 21, 610, 88, 680, 558, 475, 396, 321, 371, 125, 869, 576, 364, 709, 141, 599, 240, 848, 880, 462, 90, 238, 568, 190, 624, 936, 873, 707, 395, 129, 634, 38, 21, 851, 326, 566, 421, 532, 413, 75, 775, 432, 822, 475, 555, 960, 139, 243, 261, 660, 996, 344, 644, 322, 835, 185, 206, 44, 101, 586, 356, 92, 767, 645, 523, 98, 241, 431, 452, 3, 871, 557, 43, 750, 505, 813, 123, 478, 28, 281, 727, 194, 325, 860, 206, 961, 210, 473, 827, 703, 826, 637, 491, 91, 697, 63, 515, 447, 953, 765, 657, 319, 48, 276, 464, 667, 372, 960, 114, 175, 910, 998, 835, 534, 840, 896, 132, 286, 144, 426, 956, 922, 241, 622, 370, 931, 423, 559, 78, 26, 784, 460, 967, 324, 890, 823, 620, 903, 364, 540, 506, 790, 880, 221, 312, 289, 291, 36, 48, 268, 212, 231, 958, 260, 400, 297, 20, 182, 110, 675, 798, 825, 701, 286, 941, 123, 324, 657, 393, 790, 358, 564, 185, 949, 330, 520, 979, 654, 433, 947, 44, 767, 654, 327, 434, 275, 938, 754, 569, 165, 329, 856, 320, 253, 783, 1000, 991, 690, 255, 864, 583, 241, 868, 543, 215, 845, 750, 943, 237, 213, 159, 948, 861, 918, 974, 892, 883, 563, 932, 49, 448, 990, 932, 176, 234, 575, 45, 117, 557, 225, 507, 158, 897, 488, 433, 420, 746, 551, 861, 437, 96, 185, 980, 394, 467, 295, 816, 123, 66, 965, 135, 226, 449, 851, 337, 123, 571, 483, 306, 249, 505, 562, 556, 823, 81, 246, 624, 545, 308, 327, 390, 861, 980, 119, 520, 310, 861, 477, 265, 640, 42, 126, 94, 115, 72, 89, 291, 604, 708, 342, 754, 508, 622, 886, 878, 501, 403, 806, 793, 940, 13, 382, 528, 454, 736, 368, 572, 444, 179, 512, 709, 488, 555, 294, 874, 452, 465, 434, 825, 901, 759, 835, 316, 675, 275, 488, 19, 12, 71, 157, 652, 937, 564, 405, 564, 247, 568, 180, 632, 513, 459, 278, 76, 188, 899, 393, 47, 621, 311, 391, 420, 580, 891, 826, 31, 918, 593, 807, 601, 537, 926, 176, 726, 143, 821, 195, 321, 651, 384, 8, 218, 86, 995, 104, 344, 943, 229, 928, 524, 99, 74, 337, 649, 54, 603, 818, 428, 604, 650, 6, 800, 582, 41, 765, 390, 57, 282, 955, 375, 67, 545, 402, 926, 587, 805, 939, 152, 155, 288, 30, 993, 192, 59, 180, 425, 332, 237, 770, 841, 509, 95, 525, 849, 765, 631, 337, 78, 590, 650, 36, 890, 787, 497, 456, 766, 223, 59, 976, 917, 258, 894, 14, 677, 41, 848, 846, 279, 31, 107, 699, 492, 127, 537, 744, 687, 683, 951, 240, 296, 130, 342, 835, 796, 27, 149, 300, 656, 94, 998, 14, 841, 682, 324, 597, 76, 365, 14, 77, 861, 522, 237, 647, 162, 109, 1, 153, 584, 177, 31, 202, 22, 589, 780, 97, 706, 814, 142, 228, 189};
    begin = std::chrono::steady_clock::now();
    list.sort();
    //std::sort необходимы итераторы произвольного доступа. List не обеспечивает произвольный доступ
    end = std::chrono::steady_clock::now();
    sortTime = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    std::cout << "The list.sort() time: " << sortTime.count() << " mis\n";

    std::forward_list<int> forwardList = {471, 650, 798, 830, 941, 729, 441, 544, 181, 189, 479, 932, 570, 469, 59, 663, 163, 461, 362, 295, 730, 394, 788, 639, 361, 445, 141, 233, 565, 37, 767, 195, 249, 321, 128, 804, 363, 523, 828, 260, 452, 125, 156, 634, 318, 916, 946, 710, 628, 698, 413, 949, 701, 19, 133, 942, 545, 170, 195, 757, 56, 475, 711, 619, 495, 962, 431, 434, 219, 513, 647, 792, 590, 316, 238, 816, 898, 107, 733, 216, 96, 688, 389, 767, 439, 648, 825, 562, 204, 309, 307, 1, 677, 237, 560, 458, 270, 881, 799, 521, 703, 464, 212, 244, 617, 435, 817, 764, 567, 427, 540, 310, 322, 453, 336, 349, 603, 106, 575, 968, 164, 781, 719, 79, 285, 642, 951, 733, 5, 457, 821, 451, 733, 251, 108, 320, 543, 84, 110, 280, 68, 523, 367, 575, 898, 232, 995, 75, 870, 46, 447, 294, 711, 175, 197, 81, 119, 614, 936, 705, 611, 693, 670, 588, 676, 232, 118, 378, 680, 115, 961, 326, 555, 57, 918, 30, 471, 393, 976, 491, 982, 71, 607, 461, 231, 493, 548, 389, 220, 483, 215, 925, 758, 291, 83, 395, 528, 637, 930, 904, 14, 363, 599, 510, 12, 812, 349, 794, 810, 932, 614, 527, 967, 121, 884, 481, 291, 662, 659, 488, 773, 854, 650, 752, 909, 555, 27, 92, 621, 790, 369, 435, 200, 45, 534, 694, 185, 545, 102, 270, 592, 978, 792, 482, 561, 892, 377, 528, 556, 68, 778, 278, 256, 898, 802, 710, 35, 956, 854, 295, 834, 687, 322, 334, 944, 943, 198, 640, 481, 647, 635, 961, 548, 914, 785, 769, 952, 965, 357, 62, 829, 924, 28, 733, 549, 276, 570, 789, 105, 215, 801, 785, 1000, 27, 532, 888, 674, 833, 109, 533, 899, 101, 289, 175, 158, 530, 58, 523, 569, 315, 660, 744, 891, 7, 927, 94, 518, 456, 547, 280, 313, 96, 587, 175, 367, 700, 304, 503, 72, 719, 596, 514, 226, 310, 480, 551, 379, 511, 610, 732, 203, 358, 282, 528, 712, 26, 140, 990, 843, 281, 809, 121, 678, 775, 361, 39, 283, 934, 980, 983, 405, 920, 554, 630, 252, 575, 282, 294, 514, 442, 735, 644, 338, 754, 425, 468, 10, 701, 689, 32, 507, 408, 930, 545, 416, 306, 38, 335, 268, 567, 633, 504, 462, 913, 843, 170, 913, 821, 524, 906, 882, 289, 49, 521, 756, 343, 822, 98, 888, 45, 921, 20, 646, 142, 297, 828, 629, 337, 996, 440, 163, 198, 259, 629, 823, 400, 851, 621, 56, 639, 400, 112, 363, 675, 879, 243, 465, 627, 10, 319, 825, 572, 26, 495, 797, 52, 185, 58, 423, 427, 424, 390, 121, 109, 816, 565, 919, 203, 807, 750, 550, 58, 873, 925, 175, 470, 28, 448, 844, 726, 30, 915, 954, 313, 770, 347, 473, 509, 662, 192, 93, 967, 733, 632, 257, 579, 835, 766, 28, 943, 144, 393, 208, 454, 5, 508, 326, 375, 117, 142, 494, 21, 610, 88, 680, 558, 475, 396, 321, 371, 125, 869, 576, 364, 709, 141, 599, 240, 848, 880, 462, 90, 238, 568, 190, 624, 936, 873, 707, 395, 129, 634, 38, 21, 851, 326, 566, 421, 532, 413, 75, 775, 432, 822, 475, 555, 960, 139, 243, 261, 660, 996, 344, 644, 322, 835, 185, 206, 44, 101, 586, 356, 92, 767, 645, 523, 98, 241, 431, 452, 3, 871, 557, 43, 750, 505, 813, 123, 478, 28, 281, 727, 194, 325, 860, 206, 961, 210, 473, 827, 703, 826, 637, 491, 91, 697, 63, 515, 447, 953, 765, 657, 319, 48, 276, 464, 667, 372, 960, 114, 175, 910, 998, 835, 534, 840, 896, 132, 286, 144, 426, 956, 922, 241, 622, 370, 931, 423, 559, 78, 26, 784, 460, 967, 324, 890, 823, 620, 903, 364, 540, 506, 790, 880, 221, 312, 289, 291, 36, 48, 268, 212, 231, 958, 260, 400, 297, 20, 182, 110, 675, 798, 825, 701, 286, 941, 123, 324, 657, 393, 790, 358, 564, 185, 949, 330, 520, 979, 654, 433, 947, 44, 767, 654, 327, 434, 275, 938, 754, 569, 165, 329, 856, 320, 253, 783, 1000, 991, 690, 255, 864, 583, 241, 868, 543, 215, 845, 750, 943, 237, 213, 159, 948, 861, 918, 974, 892, 883, 563, 932, 49, 448, 990, 932, 176, 234, 575, 45, 117, 557, 225, 507, 158, 897, 488, 433, 420, 746, 551, 861, 437, 96, 185, 980, 394, 467, 295, 816, 123, 66, 965, 135, 226, 449, 851, 337, 123, 571, 483, 306, 249, 505, 562, 556, 823, 81, 246, 624, 545, 308, 327, 390, 861, 980, 119, 520, 310, 861, 477, 265, 640, 42, 126, 94, 115, 72, 89, 291, 604, 708, 342, 754, 508, 622, 886, 878, 501, 403, 806, 793, 940, 13, 382, 528, 454, 736, 368, 572, 444, 179, 512, 709, 488, 555, 294, 874, 452, 465, 434, 825, 901, 759, 835, 316, 675, 275, 488, 19, 12, 71, 157, 652, 937, 564, 405, 564, 247, 568, 180, 632, 513, 459, 278, 76, 188, 899, 393, 47, 621, 311, 391, 420, 580, 891, 826, 31, 918, 593, 807, 601, 537, 926, 176, 726, 143, 821, 195, 321, 651, 384, 8, 218, 86, 995, 104, 344, 943, 229, 928, 524, 99, 74, 337, 649, 54, 603, 818, 428, 604, 650, 6, 800, 582, 41, 765, 390, 57, 282, 955, 375, 67, 545, 402, 926, 587, 805, 939, 152, 155, 288, 30, 993, 192, 59, 180, 425, 332, 237, 770, 841, 509, 95, 525, 849, 765, 631, 337, 78, 590, 650, 36, 890, 787, 497, 456, 766, 223, 59, 976, 917, 258, 894, 14, 677, 41, 848, 846, 279, 31, 107, 699, 492, 127, 537, 744, 687, 683, 951, 240, 296, 130, 342, 835, 796, 27, 149, 300, 656, 94, 998, 14, 841, 682, 324, 597, 76, 365, 14, 77, 861, 522, 237, 647, 162, 109, 1, 153, 584, 177, 31, 202, 22, 589, 780, 97, 706, 814, 142, 228, 189};
    begin = std::chrono::steady_clock::now();
    forwardList.sort();
    //аналогично
    end = std::chrono::steady_clock::now();
    sortTime = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    std::cout << "The forward_list.sort() time: " << sortTime.count() << " mis\n";


}
