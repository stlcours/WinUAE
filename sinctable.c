 /*
  * Table of the integral of the sinc function modulated by the blackman window
  * (c) Antti S. Lankila 2006
  * 
  * Theory of operation
  * 
  * Paula synthesizes audio as a pulse waveform at a 3.54 MHz rate. This
  * fact may be exploited for performing samplerate conversion to 44.1 kHz
  * fast way using convolution with the sinc function, by recognizing that
  * convolution with a constant is the integral of the convolution function
  * multiplied by the constant. Therefore it follows that the convolution
  * can be evaluated as a piecewise sum of such integrals.
  *
  * The sinc function is evaluated for points -2048 to +2047, oscillating at
  * a rate to cause filter cutoff point around 20 kHz in the 3.54 MHz sampling
  * frequency. The function is then windowed and numerically integrated, and
  * scaled in such a fashion to start the integral from -65536 and end at 65536.
  * (The actual values are somewhat arbitrary, as only the difference between
  *  values matter.) However, this arrangement is symmetrical and gives 2^17 bits
  * of resolution for the table, or about -80 dB signal-to-noise ratio across
  * the 1.77 MHz audio spectrum. Additionally, the filter response falls very
  * close to the minimum at 22.05 kHz, thus avoiding aliasing artifacts.
  *
  * This table is computed by the program contrib/sinc-integral.py, using
  * the following parameters:
  *
  * convolution_size = 4096
  * sampling_freq = 3541200
  * stopfreq = 20000
  */

const int winsinc_integral[4096] = {
-65536, -65536, -65536, -65536, -65536, -65536, -65536, -65536, -65536, -65536,
-65536, -65536, -65536, -65536, -65536, -65536, -65536, -65536, -65536, -65536,
-65536, -65536, -65536, -65536, -65536, -65536, -65536, -65536, -65536, -65536,
-65536, -65536, -65536, -65536, -65536, -65536, -65536, -65536, -65536, -65536,
-65536, -65536, -65536, -65536, -65536, -65536, -65536, -65536, -65536, -65536,
-65536, -65536, -65536, -65536, -65536, -65536, -65536, -65536, -65536, -65536,
-65536, -65536, -65536, -65536, -65536, -65536, -65536, -65536, -65536, -65536,
-65536, -65536, -65536, -65535, -65535, -65535, -65535, -65535, -65535, -65535,
-65535, -65535, -65535, -65535, -65535, -65535, -65535, -65535, -65535, -65535,
-65535, -65535, -65535, -65535, -65535, -65535, -65535, -65535, -65535, -65535,
-65535, -65535, -65535, -65535, -65535, -65535, -65535, -65535, -65535, -65535,
-65535, -65535, -65535, -65535, -65535, -65535, -65535, -65535, -65535, -65535,
-65536, -65536, -65536, -65536, -65536, -65536, -65536, -65536, -65536, -65536,
-65536, -65536, -65536, -65536, -65536, -65536, -65537, -65537, -65537, -65537,
-65537, -65537, -65537, -65537, -65537, -65537, -65537, -65538, -65538, -65538,
-65538, -65538, -65538, -65538, -65538, -65538, -65539, -65539, -65539, -65539,
-65539, -65539, -65539, -65539, -65539, -65539, -65540, -65540, -65540, -65540,
-65540, -65540, -65540, -65540, -65540, -65540, -65540, -65540, -65540, -65541,
-65541, -65541, -65541, -65541, -65541, -65541, -65541, -65541, -65541, -65541,
-65541, -65541, -65541, -65541, -65541, -65541, -65541, -65541, -65540, -65540,
-65540, -65540, -65540, -65540, -65540, -65540, -65540, -65540, -65539, -65539,
-65539, -65539, -65539, -65539, -65539, -65538, -65538, -65538, -65538, -65538,
-65537, -65537, -65537, -65537, -65536, -65536, -65536, -65536, -65535, -65535,
-65535, -65535, -65534, -65534, -65534, -65533, -65533, -65533, -65533, -65532,
-65532, -65532, -65531, -65531, -65531, -65531, -65530, -65530, -65530, -65530,
-65529, -65529, -65529, -65528, -65528, -65528, -65528, -65528, -65527, -65527,
-65527, -65527, -65527, -65526, -65526, -65526, -65526, -65526, -65526, -65525,
-65525, -65525, -65525, -65525, -65525, -65525, -65525, -65525, -65525, -65525,
-65525, -65525, -65525, -65525, -65525, -65526, -65526, -65526, -65526, -65526,
-65526, -65527, -65527, -65527, -65527, -65528, -65528, -65528, -65529, -65529,
-65529, -65530, -65530, -65530, -65531, -65531, -65532, -65532, -65532, -65533,
-65533, -65534, -65534, -65535, -65535, -65536, -65537, -65537, -65538, -65538,
-65539, -65539, -65540, -65541, -65541, -65542, -65542, -65543, -65543, -65544,
-65545, -65545, -65546, -65546, -65547, -65547, -65548, -65549, -65549, -65550,
-65550, -65551, -65551, -65552, -65552, -65553, -65553, -65553, -65554, -65554,
-65555, -65555, -65555, -65556, -65556, -65556, -65556, -65557, -65557, -65557,
-65557, -65557, -65557, -65558, -65558, -65558, -65558, -65558, -65558, -65557,
-65557, -65557, -65557, -65557, -65557, -65556, -65556, -65556, -65555, -65555,
-65555, -65554, -65554, -65553, -65553, -65552, -65552, -65551, -65550, -65550,
-65549, -65548, -65547, -65547, -65546, -65545, -65544, -65543, -65543, -65542,
-65541, -65540, -65539, -65538, -65537, -65536, -65535, -65534, -65533, -65532,
-65531, -65530, -65529, -65528, -65527, -65526, -65525, -65524, -65523, -65522,
-65521, -65520, -65519, -65518, -65517, -65516, -65515, -65514, -65513, -65512,
-65511, -65510, -65509, -65509, -65508, -65507, -65506, -65506, -65505, -65504,
-65504, -65503, -65503, -65502, -65502, -65501, -65501, -65501, -65500, -65500,
-65500, -65500, -65500, -65499, -65499, -65499, -65500, -65500, -65500, -65500,
-65500, -65501, -65501, -65501, -65502, -65502, -65503, -65504, -65504, -65505,
-65506, -65506, -65507, -65508, -65509, -65510, -65511, -65512, -65513, -65515,
-65516, -65517, -65518, -65520, -65521, -65522, -65524, -65525, -65527, -65528,
-65530, -65531, -65533, -65534, -65536, -65538, -65539, -65541, -65543, -65544,
-65546, -65548, -65550, -65551, -65553, -65555, -65556, -65558, -65560, -65561,
-65563, -65565, -65566, -65568, -65569, -65571, -65572, -65574, -65575, -65577,
-65578, -65579, -65581, -65582, -65583, -65584, -65585, -65586, -65587, -65588,
-65589, -65590, -65591, -65592, -65592, -65593, -65593, -65594, -65594, -65594,
-65595, -65595, -65595, -65595, -65595, -65595, -65594, -65594, -65594, -65593,
-65593, -65592, -65591, -65591, -65590, -65589, -65588, -65587, -65586, -65584,
-65583, -65582, -65580, -65579, -65577, -65575, -65574, -65572, -65570, -65568,
-65566, -65564, -65562, -65560, -65558, -65556, -65553, -65551, -65549, -65546,
-65544, -65541, -65539, -65536, -65534, -65531, -65529, -65526, -65523, -65521,
-65518, -65515, -65513, -65510, -65508, -65505, -65502, -65500, -65497, -65495,
-65492, -65490, -65487, -65485, -65483, -65480, -65478, -65476, -65474, -65472,
-65470, -65468, -65466, -65464, -65463, -65461, -65459, -65458, -65457, -65455,
-65454, -65453, -65452, -65451, -65450, -65449, -65449, -65448, -65448, -65448,
-65448, -65447, -65448, -65448, -65448, -65448, -65449, -65450, -65450, -65451,
-65452, -65453, -65454, -65456, -65457, -65459, -65460, -65462, -65464, -65466,
-65468, -65470, -65473, -65475, -65478, -65480, -65483, -65486, -65489, -65492,
-65495, -65498, -65501, -65504, -65508, -65511, -65515, -65518, -65522, -65525,
-65529, -65533, -65537, -65540, -65544, -65548, -65552, -65556, -65560, -65563,
-65567, -65571, -65575, -65579, -65583, -65587, -65590, -65594, -65598, -65601,
-65605, -65609, -65612, -65615, -65619, -65622, -65625, -65628, -65631, -65634,
-65637, -65640, -65642, -65645, -65647, -65649, -65651, -65653, -65655, -65657,
-65658, -65660, -65661, -65662, -65663, -65664, -65664, -65665, -65665, -65665,
-65665, -65665, -65665, -65665, -65664, -65663, -65662, -65661, -65660, -65658,
-65656, -65655, -65653, -65650, -65648, -65646, -65643, -65640, -65637, -65634,
-65631, -65627, -65624, -65620, -65616, -65612, -65608, -65604, -65600, -65595,
-65591, -65586, -65581, -65576, -65571, -65566, -65561, -65556, -65551, -65545,
-65540, -65535, -65529, -65524, -65518, -65513, -65507, -65501, -65496, -65490,
-65485, -65479, -65474, -65468, -65463, -65458, -65452, -65447, -65442, -65437,
-65432, -65427, -65422, -65417, -65413, -65408, -65404, -65400, -65396, -65392,
-65388, -65385, -65381, -65378, -65375, -65372, -65369, -65367, -65365, -65362,
-65361, -65359, -65357, -65356, -65355, -65354, -65354, -65353, -65353, -65353,
-65354, -65354, -65355, -65356, -65357, -65359, -65361, -65363, -65365, -65367,
-65370, -65373, -65376, -65379, -65383, -65387, -65391, -65395, -65400, -65404,
-65409, -65414, -65420, -65425, -65431, -65437, -65443, -65449, -65455, -65461,
-65468, -65475, -65482, -65489, -65496, -65503, -65510, -65518, -65525, -65533,
-65540, -65548, -65556, -65563, -65571, -65579, -65587, -65594, -65602, -65610,
-65617, -65625, -65633, -65640, -65648, -65655, -65662, -65669, -65676, -65683,
-65690, -65696, -65703, -65709, -65715, -65721, -65727, -65732, -65738, -65743,
-65748, -65752, -65757, -65761, -65765, -65768, -65771, -65775, -65777, -65780,
-65782, -65784, -65786, -65787, -65788, -65788, -65789, -65789, -65789, -65788,
-65787, -65786, -65784, -65782, -65780, -65777, -65775, -65771, -65768, -65764,
-65760, -65755, -65750, -65745, -65740, -65734, -65728, -65722, -65715, -65709,
-65701, -65694, -65686, -65679, -65671, -65662, -65654, -65645, -65636, -65627,
-65618, -65608, -65598, -65589, -65579, -65569, -65558, -65548, -65538, -65527,
-65517, -65507, -65496, -65485, -65475, -65464, -65454, -65443, -65433, -65422,
-65412, -65402, -65392, -65381, -65372, -65362, -65352, -65343, -65333, -65324,
-65316, -65307, -65299, -65290, -65282, -65275, -65268, -65260, -65254, -65247,
-65241, -65235, -65230, -65225, -65220, -65216, -65212, -65208, -65205, -65202,
-65200, -65198, -65196, -65195, -65195, -65194, -65194, -65195, -65196, -65197,
-65199, -65202, -65205, -65208, -65211, -65216, -65220, -65225, -65230, -65236,
-65243, -65249, -65256, -65264, -65272, -65280, -65289, -65298, -65307, -65317,
-65327, -65337, -65348, -65359, -65370, -65382, -65394, -65406, -65418, -65431,
-65444, -65457, -65470, -65483, -65497, -65511, -65524, -65538, -65552, -65566,
-65581, -65595, -65609, -65623, -65637, -65651, -65665, -65679, -65693, -65707,
-65721, -65734, -65748, -65761, -65774, -65786, -65799, -65811, -65823, -65835,
-65846, -65857, -65868, -65878, -65888, -65898, -65907, -65916, -65924, -65932,
-65940, -65947, -65953, -65960, -65965, -65970, -65975, -65979, -65982, -65985,
-65987, -65989, -65990, -65991, -65991, -65991, -65990, -65988, -65986, -65983,
-65980, -65976, -65971, -65966, -65960, -65954, -65947, -65940, -65932, -65923,
-65914, -65904, -65894, -65883, -65872, -65861, -65848, -65836, -65823, -65809,
-65795, -65781, -65766, -65751, -65735, -65719, -65703, -65687, -65670, -65653,
-65635, -65618, -65600, -65582, -65564, -65545, -65527, -65508, -65490, -65471,
-65452, -65434, -65415, -65396, -65378, -65359, -65341, -65322, -65304, -65286,
-65269, -65251, -65234, -65217, -65200, -65184, -65168, -65152, -65137, -65122,
-65108, -65094, -65081, -65068, -65055, -65044, -65032, -65021, -65011, -65002,
-64993, -64984, -64977, -64970, -64963, -64958, -64953, -64949, -64945, -64942,
-64940, -64939, -64939, -64939, -64940, -64942, -64944, -64947, -64951, -64956,
-64962, -64968, -64975, -64983, -64992, -65001, -65011, -65022, -65034, -65046,
-65059, -65072, -65087, -65102, -65117, -65134, -65150, -65168, -65186, -65204,
-65223, -65243, -65263, -65284, -65305, -65326, -65348, -65370, -65393, -65415,
-65438, -65462, -65485, -65509, -65533, -65557, -65582, -65606, -65630, -65655,
-65679, -65704, -65728, -65752, -65776, -65800, -65824, -65847, -65871, -65894,
-65916, -65939, -65961, -65982, -66003, -66024, -66044, -66063, -66082, -66101,
-66119, -66136, -66152, -66168, -66183, -66198, -66211, -66224, -66236, -66248,
-66258, -66268, -66276, -66284, -66291, -66297, -66302, -66306, -66309, -66311,
-66313, -66313, -66312, -66310, -66307, -66304, -66299, -66293, -66287, -66279,
-66270, -66260, -66250, -66238, -66226, -66212, -66197, -66182, -66166, -66149,
-66130, -66112, -66092, -66071, -66050, -66028, -66005, -65981, -65957, -65931,
-65906, -65879, -65853, -65825, -65797, -65769, -65740, -65710, -65681, -65650,
-65620, -65589, -65558, -65527, -65496, -65464, -65433, -65401, -65370, -65338,
-65306, -65275, -65244, -65213, -65182, -65151, -65121, -65091, -65062, -65033,
-65004, -64976, -64948, -64921, -64895, -64869, -64844, -64820, -64797, -64774,
-64752, -64731, -64711, -64692, -64674, -64657, -64641, -64626, -64612, -64599,
-64587, -64576, -64567, -64558, -64551, -64545, -64541, -64537, -64535, -64534,
-64534, -64536, -64539, -64543, -64548, -64555, -64563, -64572, -64583, -64595,
-64608, -64622, -64638, -64654, -64673, -64692, -64712, -64734, -64757, -64780,
-64805, -64831, -64858, -64887, -64916, -64946, -64977, -65008, -65041, -65075,
-65109, -65144, -65180, -65216, -65253, -65291, -65329, -65367, -65406, -65446,
-65485, -65525, -65566, -65606, -65647, -65688, -65728, -65769, -65810, -65850,
-65891, -65931, -65971, -66010, -66049, -66088, -66126, -66164, -66201, -66238,
-66274, -66309, -66343, -66377, -66409, -66441, -66472, -66502, -66530, -66558,
-66584, -66610, -66634, -66656, -66678, -66698, -66717, -66734, -66750, -66765,
-66778, -66789, -66799, -66808, -66815, -66820, -66824, -66826, -66826, -66825,
-66822, -66818, -66812, -66804, -66795, -66784, -66771, -66756, -66740, -66723,
-66704, -66683, -66660, -66636, -66611, -66584, -66555, -66525, -66494, -66461,
-66427, -66391, -66355, -66317, -66277, -66237, -66195, -66153, -66109, -66065,
-66019, -65973, -65925, -65877, -65829, -65779, -65729, -65679, -65628, -65576,
-65524, -65472, -65420, -65368, -65315, -65263, -65210, -65158, -65106, -65054,
-65002, -64951, -64900, -64850, -64800, -64751, -64703, -64655, -64608, -64563,
-64518, -64474, -64431, -64390, -64349, -64310, -64272, -64236, -64201, -64168,
-64136, -64106, -64077, -64050, -64025, -64001, -63980, -63960, -63942, -63926,
-63912, -63900, -63890, -63882, -63876, -63873, -63871, -63871, -63874, -63878,
-63885, -63894, -63905, -63918, -63934, -63951, -63971, -63992, -64016, -64042,
-64070, -64100, -64132, -64166, -64202, -64239, -64279, -64321, -64364, -64409,
-64456, -64504, -64554, -64606, -64659, -64713, -64769, -64826, -64885, -64944,
-65005, -65067, -65129, -65193, -65257, -65323, -65388, -65455, -65522, -65589,
-65657, -65725, -65793, -65861, -65929, -65997, -66065, -66133, -66200, -66267,
-66333, -66399, -66464, -66528, -66592, -66654, -66716, -66776, -66835, -66893,
-66949, -67004, -67057, -67109, -67159, -67207, -67254, -67298, -67341, -67382,
-67420, -67456, -67490, -67522, -67552, -67579, -67603, -67626, -67645, -67662,
-67677, -67688, -67698, -67704, -67708, -67709, -67707, -67702, -67695, -67685,
-67672, -67656, -67637, -67616, -67592, -67565, -67535, -67503, -67468, -67430,
-67389, -67346, -67300, -67252, -67201, -67148, -67093, -67035, -66974, -66912,
-66847, -66781, -66712, -66641, -66569, -66495, -66419, -66341, -66262, -66181,
-66099, -66016, -65932, -65846, -65760, -65673, -65585, -65496, -65407, -65318,
-65228, -65138, -65048, -64957, -64868, -64778, -64689, -64600, -64512, -64424,
-64337, -64252, -64167, -64084, -64002, -63921, -63842, -63764, -63688, -63614,
-63542, -63472, -63405, -63339, -63276, -63215, -63157, -63102, -63049, -62999,
-62952, -62908, -62867, -62829, -62795, -62763, -62735, -62711, -62690, -62672,
-62658, -62647, -62640, -62637, -62638, -62642, -62650, -62661, -62677, -62696,
-62719, -62746, -62776, -62810, -62848, -62890, -62935, -62985, -63037, -63093,
-63153, -63217, -63283, -63353, -63427, -63503, -63583, -63666, -63752, -63841,
-63933, -64027, -64124, -64223, -64325, -64430, -64536, -64645, -64755, -64867,
-64981, -65097, -65214, -65332, -65452, -65572, -65693, -65816, -65938, -66061,
-66184, -66308, -66431, -66554, -66677, -66799, -66921, -67042, -67161, -67280,
-67397, -67513, -67627, -67739, -67850, -67958, -68064, -68168, -68269, -68367,
-68463, -68555, -68644, -68730, -68813, -68892, -68967, -69039, -69106, -69170,
-69229, -69284, -69335, -69381, -69423, -69460, -69492, -69519, -69542, -69559,
-69572, -69579, -69581, -69578, -69570, -69556, -69537, -69513, -69483, -69448,
-69408, -69362, -69311, -69255, -69193, -69126, -69054, -68976, -68894, -68806,
-68714, -68616, -68514, -68406, -68294, -68178, -68057, -67932, -67802, -67668,
-67531, -67389, -67244, -67095, -66942, -66787, -66628, -66467, -66303, -66136,
-65967, -65795, -65622, -65447, -65270, -65092, -64913, -64733, -64552, -64371,
-64190, -64008, -63827, -63646, -63466, -63286, -63108, -62931, -62756, -62583,
-62411, -62242, -62076, -61913, -61752, -61595, -61441, -61291, -61145, -61004,
-60866, -60734, -60606, -60484, -60366, -60255, -60148, -60048, -59954, -59867,
-59786, -59711, -59643, -59583, -59529, -59483, -59444, -59413, -59390, -59374,
-59367, -59367, -59376, -59393, -59418, -59452, -59494, -59544, -59603, -59671,
-59748, -59833, -59926, -60028, -60139, -60259, -60386, -60523, -60668, -60821,
-60982, -61152, -61329, -61515, -61708, -61909, -62117, -62333, -62556, -62786,
-63023, -63266, -63516, -63772, -64034, -64301, -64574, -64852, -65135, -65423,
-65714, -66010, -66310, -66612, -66918, -67226, -67537, -67850, -68164, -68479,
-68795, -69112, -69429, -69745, -70060, -70375, -70687, -70998, -71306, -71611,
-71913, -72211, -72505, -72794, -73078, -73357, -73629, -73895, -74153, -74405,
-74648, -74883, -75109, -75326, -75533, -75730, -75917, -76092, -76255, -76407,
-76546, -76672, -76785, -76884, -76969, -77039, -77095, -77134, -77158, -77166,
-77157, -77132, -77088, -77027, -76948, -76851, -76735, -76600, -76445, -76271,
-76077, -75863, -75628, -75372, -75096, -74798, -74479, -74138, -73776, -73391,
-72984, -72555, -72104, -71630, -71134, -70615, -70073, -69508, -68920, -68309,
-67676, -67020, -66340, -65638, -64913, -64165, -63395, -62602, -61787, -60950,
-60090, -59208, -58305, -57380, -56433, -55466, -54477, -53468, -52439, -51389,
-50320, -49231, -48123, -46996, -45851, -44687, -43506, -42308, -41093, -39861,
-38613, -37350, -36071, -34778, -33471, -32150, -30816, -29470, -28111, -26740,
-25359, -23967, -22565, -21154, -19734, -18305, -16869, -15426, -13977, -12521,
-11061,  -9595,  -8126,  -6653,  -5178,  -3700,  -2221,   -740,    740,   2220,
  3700,   5177,   6653,   8126,   9595,  11060,  12521,  13976,  15426,  16869,
 18305,  19733,  21153,  22565,  23967,  25358,  26740,  28110,  29469,  30816,
 32150,  33471,  34778,  36071,  37349,  38613,  39860,  41092,  42307,  43506,
 44687,  45850,  46996,  48122,  49230,  50319,  51389,  52438,  53468,  54477,
 55466,  56433,  57380,  58305,  59208,  60090,  60949,  61787,  62602,  63395,
 64165,  64913,  65638,  66340,  67019,  67676,  68309,  68920,  69507,  70072,
 70614,  71133,  71630,  72104,  72555,  72984,  73391,  73775,  74138,  74479,
 74798,  75095,  75372,  75628,  75862,  76077,  76271,  76445,  76600,  76735,
 76851,  76948,  77027,  77088,  77131,  77157,  77166,  77158,  77134,  77094,
 77039,  76969,  76884,  76785,  76672,  76546,  76407,  76255,  76092,  75916,
 75730,  75533,  75326,  75109,  74883,  74648,  74404,  74153,  73894,  73629,
 73356,  73078,  72794,  72505,  72211,  71913,  71611,  71306,  70998,  70687,
 70374,  70060,  69745,  69428,  69112,  68795,  68479,  68163,  67849,  67537,
 67226,  66918,  66612,  66309,  66010,  65714,  65422,  65135,  64852,  64574,
 64301,  64033,  63772,  63516,  63266,  63023,  62786,  62556,  62333,  62117,
 61908,  61707,  61514,  61329,  61151,  60982,  60820,  60667,  60522,  60386,
 60258,  60139,  60028,  59926,  59832,  59747,  59671,  59603,  59544,  59493,
 59451,  59418,  59392,  59375,  59367,  59366,  59374,  59389,  59413,  59444,
 59483,  59529,  59582,  59643,  59711,  59785,  59866,  59954,  60048,  60148,
 60254,  60366,  60483,  60606,  60734,  60866,  61003,  61145,  61291,  61441,
 61595,  61752,  61912,  62076,  62242,  62411,  62582,  62756,  62931,  63108,
 63286,  63465,  63645,  63826,  64008,  64189,  64371,  64552,  64733,  64913,
 65092,  65270,  65447,  65622,  65795,  65966,  66135,  66302,  66466,  66628,
 66787,  66942,  67094,  67243,  67389,  67530,  67668,  67802,  67931,  68057,
 68178,  68294,  68406,  68513,  68616,  68713,  68806,  68894,  68976,  69053,
 69126,  69193,  69254,  69311,  69362,  69408,  69448,  69483,  69512,  69537,
 69556,  69569,  69578,  69581,  69579,  69571,  69559,  69541,  69519,  69492,
 69459,  69422,  69381,  69335,  69284,  69229,  69169,  69106,  69038,  68967,
 68891,  68812,  68730,  68644,  68555,  68462,  68367,  68268,  68167,  68064,
 67958,  67849,  67739,  67627,  67513,  67397,  67280,  67161,  67041,  66921,
 66799,  66677,  66554,  66431,  66307,  66184,  66061,  65938,  65815,  65693,
 65572,  65451,  65332,  65214,  65097,  64981,  64867,  64755,  64644,  64536,
 64429,  64325,  64223,  64124,  64027,  63932,  63841,  63752,  63666,  63583,
 63503,  63426,  63353,  63283,  63216,  63153,  63093,  63037,  62984,  62935,
 62890,  62848,  62810,  62776,  62745,  62719,  62696,  62676,  62661,  62649,
 62641,  62637,  62637,  62640,  62647,  62657,  62672,  62689,  62710,  62735,
 62763,  62794,  62829,  62867,  62908,  62952,  62999,  63049,  63101,  63157,
 63215,  63276,  63339,  63404,  63472,  63542,  63614,  63688,  63764,  63841,
 63920,  64001,  64083,  64167,  64251,  64337,  64424,  64511,  64599,  64688,
 64778,  64867,  64957,  65047,  65137,  65227,  65317,  65407,  65496,  65584,
 65672,  65760,  65846,  65931,  66016,  66099,  66181,  66261,  66341,  66418,
 66494,  66568,  66641,  66712,  66780,  66847,  66912,  66974,  67034,  67092,
 67148,  67201,  67252,  67300,  67346,  67389,  67429,  67467,  67502,  67535,
 67565,  67592,  67616,  67637,  67656,  67671,  67684,  67695,  67702,  67707,
 67708,  67707,  67704,  67697,  67688,  67676,  67662,  67645,  67625,  67603,
 67578,  67551,  67522,  67490,  67456,  67420,  67381,  67341,  67298,  67253,
 67207,  67159,  67109,  67057,  67004,  66949,  66892,  66835,  66775,  66715,
 66654,  66591,  66528,  66464,  66399,  66333,  66267,  66200,  66133,  66065,
 65997,  65929,  65861,  65792,  65724,  65656,  65589,  65521,  65454,  65388,
 65322,  65257,  65193,  65129,  65066,  65005,  64944,  64884,  64826,  64769,
 64713,  64658,  64605,  64554,  64504,  64455,  64409,  64364,  64320,  64279,
 64239,  64201,  64165,  64131,  64100,  64070,  64042,  64016,  63992,  63970,
 63951,  63933,  63918,  63905,  63894,  63885,  63878,  63873,  63871,  63870,
 63872,  63876,  63882,  63890,  63900,  63912,  63926,  63942,  63960,  63979,
 64001,  64024,  64050,  64077,  64105,  64136,  64167,  64201,  64236,  64272,
 64310,  64349,  64389,  64431,  64474,  64517,  64562,  64608,  64655,  64702,
 64751,  64800,  64849,  64900,  64951,  65002,  65053,  65105,  65158,  65210,
 65262,  65315,  65367,  65420,  65472,  65524,  65576,  65627,  65678,  65729,
 65779,  65828,  65877,  65925,  65972,  66019,  66064,  66109,  66152,  66195,
 66237,  66277,  66316,  66354,  66391,  66427,  66461,  66494,  66525,  66555,
 66583,  66610,  66636,  66660,  66682,  66703,  66722,  66740,  66756,  66770,
 66783,  66794,  66804,  66811,  66818,  66822,  66825,  66826,  66826,  66823,
 66820,  66814,  66808,  66799,  66789,  66777,  66764,  66750,  66734,  66717,
 66698,  66678,  66656,  66633,  66609,  66584,  66558,  66530,  66501,  66472,
 66441,  66409,  66376,  66343,  66309,  66273,  66238,  66201,  66164,  66126,
 66088,  66049,  66010,  65970,  65930,  65890,  65850,  65809,  65769,  65728,
 65687,  65646,  65606,  65565,  65525,  65485,  65445,  65406,  65367,  65328,
 65290,  65253,  65216,  65179,  65144,  65109,  65074,  65041,  65008,  64976,
 64945,  64915,  64886,  64858,  64831,  64805,  64780,  64756,  64733,  64712,
 64691,  64672,  64654,  64637,  64622,  64607,  64594,  64582,  64572,  64563,
 64555,  64548,  64542,  64538,  64535,  64534,  64534,  64534,  64537,  64540,
 64545,  64551,  64558,  64566,  64576,  64587,  64598,  64611,  64625,  64640,
 64657,  64674,  64692,  64711,  64731,  64752,  64774,  64796,  64820,  64844,
 64869,  64895,  64921,  64948,  64976,  65004,  65032,  65061,  65091,  65121,
 65151,  65182,  65212,  65243,  65275,  65306,  65338,  65369,  65401,  65432,
 65464,  65495,  65527,  65558,  65589,  65620,  65650,  65680,  65710,  65739,
 65768,  65797,  65825,  65852,  65879,  65905,  65931,  65956,  65981,  66004,
 66027,  66049,  66071,  66091,  66111,  66130,  66148,  66165,  66182,  66197,
 66212,  66225,  66238,  66249,  66260,  66270,  66278,  66286,  66293,  66299,
 66303,  66307,  66310,  66312,  66312,  66312,  66311,  66309,  66306,  66302,
 66296,  66291,  66284,  66276,  66267,  66258,  66247,  66236,  66224,  66211,
 66197,  66183,  66168,  66152,  66135,  66118,  66100,  66082,  66063,  66043,
 66023,  66003,  65982,  65960,  65938,  65916,  65893,  65870,  65847,  65824,
 65800,  65776,  65752,  65728,  65703,  65679,  65655,  65630,  65606,  65581,
 65557,  65533,  65509,  65485,  65462,  65438,  65415,  65392,  65370,  65347,
 65326,  65304,  65283,  65263,  65243,  65223,  65204,  65185,  65167,  65150,
 65133,  65117,  65101,  65086,  65072,  65058,  65045,  65033,  65022,  65011,
 65001,  64991,  64983,  64975,  64968,  64961,  64956,  64951,  64947,  64944,
 64941,  64939,  64938,  64938,  64939,  64940,  64942,  64945,  64948,  64953,
 64957,  64963,  64969,  64976,  64984,  64992,  65001,  65011,  65021,  65032,
 65043,  65055,  65067,  65080,  65094,  65108,  65122,  65137,  65152,  65168,
 65184,  65200,  65217,  65234,  65251,  65268,  65286,  65304,  65322,  65340,
 65359,  65377,  65396,  65415,  65433,  65452,  65471,  65489,  65508,  65527,
 65545,  65563,  65581,  65599,  65617,  65635,  65652,  65669,  65686,  65703,
 65719,  65735,  65750,  65766,  65780,  65795,  65809,  65822,  65835,  65848,
 65860,  65872,  65883,  65894,  65904,  65914,  65923,  65931,  65939,  65947,
 65954,  65960,  65966,  65971,  65975,  65979,  65983,  65985,  65988,  65989,
 65990,  65991,  65991,  65990,  65989,  65987,  65985,  65982,  65978,  65974,
 65970,  65965,  65959,  65953,  65947,  65940,  65932,  65924,  65916,  65907,
 65898,  65888,  65878,  65868,  65857,  65846,  65835,  65823,  65811,  65799,
 65786,  65773,  65760,  65747,  65734,  65720,  65707,  65693,  65679,  65665,
 65651,  65637,  65623,  65609,  65594,  65580,  65566,  65552,  65538,  65524,
 65510,  65497,  65483,  65470,  65456,  65443,  65431,  65418,  65406,  65393,
 65381,  65370,  65359,  65347,  65337,  65326,  65316,  65307,  65297,  65288,
 65280,  65271,  65263,  65256,  65249,  65242,  65236,  65230,  65225,  65220,
 65215,  65211,  65207,  65204,  65201,  65199,  65197,  65196,  65195,  65194,
 65194,  65194,  65195,  65196,  65198,  65200,  65202,  65205,  65208,  65211,
 65215,  65220,  65225,  65230,  65235,  65241,  65247,  65253,  65260,  65267,
 65274,  65282,  65290,  65298,  65307,  65315,  65324,  65333,  65342,  65352,
 65361,  65371,  65381,  65391,  65401,  65412,  65422,  65432,  65443,  65453,
 65464,  65474,  65485,  65496,  65506,  65517,  65527,  65538,  65548,  65558,
 65568,  65578,  65588,  65598,  65608,  65617,  65626,  65636,  65645,  65653,
 65662,  65670,  65678,  65686,  65694,  65701,  65708,  65715,  65722,  65728,
 65734,  65740,  65745,  65750,  65755,  65759,  65764,  65767,  65771,  65774,
 65777,  65780,  65782,  65784,  65785,  65787,  65788,  65788,  65788,  65788,
 65788,  65787,  65786,  65785,  65784,  65782,  65779,  65777,  65774,  65771,
 65768,  65764,  65760,  65756,  65752,  65747,  65742,  65737,  65732,  65726,
 65721,  65715,  65709,  65702,  65696,  65689,  65683,  65676,  65669,  65662,
 65655,  65647,  65640,  65632,  65625,  65617,  65609,  65602,  65594,  65586,
 65579,  65571,  65563,  65555,  65548,  65540,  65532,  65525,  65517,  65510,
 65503,  65495,  65488,  65481,  65474,  65468,  65461,  65455,  65448,  65442,
 65436,  65430,  65425,  65419,  65414,  65409,  65404,  65399,  65395,  65391,
 65387,  65383,  65379,  65376,  65373,  65370,  65367,  65364,  65362,  65360,
 65358,  65357,  65356,  65355,  65354,  65353,  65353,  65353,  65353,  65353,
 65354,  65355,  65356,  65357,  65359,  65360,  65362,  65364,  65367,  65369,
 65372,  65375,  65378,  65381,  65384,  65388,  65392,  65396,  65400,  65404,
 65408,  65413,  65417,  65422,  65427,  65431,  65436,  65442,  65447,  65452,
 65457,  65463,  65468,  65473,  65479,  65484,  65490,  65496,  65501,  65507,
 65512,  65518,  65523,  65529,  65534,  65540,  65545,  65550,  65556,  65561,
 65566,  65571,  65576,  65581,  65586,  65590,  65595,  65599,  65604,  65608,
 65612,  65616,  65620,  65623,  65627,  65630,  65634,  65637,  65640,  65643,
 65645,  65648,  65650,  65652,  65654,  65656,  65658,  65659,  65661,  65662,
 65663,  65664,  65664,  65665,  65665,  65665,  65665,  65665,  65665,  65664,
 65663,  65663,  65662,  65661,  65659,  65658,  65656,  65655,  65653,  65651,
 65649,  65647,  65644,  65642,  65639,  65637,  65634,  65631,  65628,  65625,
 65622,  65618,  65615,  65612,  65608,  65605,  65601,  65597,  65594,  65590,
 65586,  65582,  65579,  65575,  65571,  65567,  65563,  65559,  65555,  65551,
 65548,  65544,  65540,  65536,  65532,  65529,  65525,  65521,  65518,  65514,
 65511,  65507,  65504,  65501,  65497,  65494,  65491,  65488,  65485,  65483,
 65480,  65477,  65475,  65472,  65470,  65468,  65466,  65464,  65462,  65460,
 65458,  65457,  65455,  65454,  65453,  65452,  65451,  65450,  65449,  65449,
 65448,  65448,  65447,  65447,  65447,  65447,  65447,  65448,  65448,  65449,
 65449,  65450,  65451,  65452,  65453,  65454,  65455,  65456,  65458,  65459,
 65461,  65462,  65464,  65466,  65468,  65470,  65472,  65474,  65476,  65478,
 65480,  65482,  65485,  65487,  65490,  65492,  65494,  65497,  65500,  65502,
 65505,  65507,  65510,  65513,  65515,  65518,  65520,  65523,  65526,  65528,
 65531,  65533,  65536,  65538,  65541,  65543,  65546,  65548,  65551,  65553,
 65555,  65557,  65560,  65562,  65564,  65566,  65568,  65570,  65572,  65573,
 65575,  65577,  65578,  65580,  65581,  65583,  65584,  65585,  65586,  65587,
 65588,  65589,  65590,  65591,  65592,  65592,  65593,  65593,  65594,  65594,
 65594,  65594,  65594,  65594,  65594,  65594,  65594,  65594,  65593,  65593,
 65592,  65592,  65591,  65590,  65590,  65589,  65588,  65587,  65586,  65585,
 65584,  65583,  65582,  65580,  65579,  65578,  65576,  65575,  65574,  65572,
 65571,  65569,  65567,  65566,  65564,  65563,  65561,  65559,  65558,  65556,
 65554,  65553,  65551,  65549,  65547,  65546,  65544,  65542,  65541,  65539,
 65537,  65536,  65534,  65533,  65531,  65529,  65528,  65526,  65525,  65523,
 65522,  65521,  65519,  65518,  65517,  65515,  65514,  65513,  65512,  65511,
 65510,  65509,  65508,  65507,  65506,  65505,  65505,  65504,  65503,  65503,
 65502,  65502,  65501,  65501,  65500,  65500,  65500,  65499,  65499,  65499,
 65499,  65499,  65499,  65499,  65499,  65499,  65500,  65500,  65500,  65501,
 65501,  65501,  65502,  65502,  65503,  65503,  65504,  65505,  65505,  65506,
 65507,  65507,  65508,  65509,  65510,  65511,  65512,  65512,  65513,  65514,
 65515,  65516,  65517,  65518,  65519,  65520,  65521,  65522,  65523,  65524,
 65525,  65527,  65528,  65529,  65530,  65531,  65532,  65533,  65534,  65535,
 65536,  65537,  65538,  65539,  65540,  65540,  65541,  65542,  65543,  65544,
 65545,  65546,  65546,  65547,  65548,  65549,  65549,  65550,  65551,  65551,
 65552,  65552,  65553,  65553,  65554,  65554,  65555,  65555,  65555,  65556,
 65556,  65556,  65556,  65557,  65557,  65557,  65557,  65557,  65557,  65557,
 65557,  65557,  65557,  65557,  65557,  65557,  65557,  65557,  65556,  65556,
 65556,  65556,  65555,  65555,  65555,  65554,  65554,  65553,  65553,  65553,
 65552,  65552,  65551,  65551,  65550,  65550,  65549,  65549,  65548,  65548,
 65547,  65547,  65546,  65545,  65545,  65544,  65544,  65543,  65542,  65542,
 65541,  65541,  65540,  65540,  65539,  65538,  65538,  65537,  65537,  65536,
 65536,  65535,  65535,  65534,  65534,  65533,  65533,  65532,  65532,  65531,
 65531,  65530,  65530,  65530,  65529,  65529,  65528,  65528,  65528,  65528,
 65527,  65527,  65527,  65526,  65526,  65526,  65526,  65526,  65525,  65525,
 65525,  65525,  65525,  65525,  65525,  65525,  65525,  65525,  65525,  65525,
 65525,  65525,  65525,  65525,  65525,  65525,  65525,  65525,  65525,  65526,
 65526,  65526,  65526,  65526,  65526,  65527,  65527,  65527,  65527,  65527,
 65528,  65528,  65528,  65528,  65529,  65529,  65529,  65529,  65530,  65530,
 65530,  65531,  65531,  65531,  65531,  65532,  65532,  65532,  65533,  65533,
 65533,  65533,  65534,  65534,  65534,  65534,  65535,  65535,  65535,  65536,
 65536,  65536,  65536,  65536,  65537,  65537,  65537,  65537,  65538,  65538,
 65538,  65538,  65538,  65539,  65539,  65539,  65539,  65539,  65539,  65539,
 65540,  65540,  65540,  65540,  65540,  65540,  65540,  65540,  65540,  65540,
 65540,  65540,  65540,  65540,  65540,  65540,  65540,  65540,  65540,  65540,
 65540,  65540,  65540,  65540,  65540,  65540,  65540,  65540,  65540,  65540,
 65540,  65540,  65540,  65540,  65540,  65540,  65539,  65539,  65539,  65539,
 65539,  65539,  65539,  65539,  65539,  65539,  65539,  65538,  65538,  65538,
 65538,  65538,  65538,  65538,  65538,  65538,  65537,  65537,  65537,  65537,
 65537,  65537,  65537,  65537,  65537,  65537,  65536,  65536,  65536,  65536,
 65536,  65536,  65536,  65536,  65536,  65536,  65536,  65536,  65536,  65535,
 65535,  65535,  65535,  65535,  65535,  65535,  65535,  65535,  65535,  65535,
 65535,  65535,  65535,  65535,  65535,  65535,  65535,  65535,  65535,  65535,
 65535,  65535,  65535,  65535,  65535,  65535,  65535,  65535,  65535,  65535,
 65535,  65535,  65535,  65535,  65535,  65535,  65535,  65535,  65535,  65535,
 65535,  65535,  65535,  65535,  65535,  65535,  65535,  65535,  65535,  65535,
 65535,  65535,  65535,  65535,  65535,  65535,  65535,  65535,  65535,  65535,
 65535,  65535,  65535,  65535,  65535,  65535,  65535,  65535,  65535,  65535,
 65535,  65535,  65535,  65535,  65535,  65536,  65536,  65536,  65536,  65536,
 65536,  65536,  65536,  65536,  65536,  65536,  65536,  65536,  65536,  65536,
 65536,  65536,  65536,  65536,  65536,  65536,  65536,  65536,  65536,  65536,
 65536,  65536,  65536,  65536,  65536,  65536,  65536,  65536,  65536,  65536,
 65536,  65536,  65536,  65536,  65536,  65536,  65536,  65536,  65536,  65536,
 65536,  65536,  65536,  65536,  65536,  65536
};
