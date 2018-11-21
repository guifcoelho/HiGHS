#include "FilereaderMps.h"
#if defined(Boost_FOUND) && !defined(OLD_PARSER)
#include "HMpsFF.h"
#endif

FilereaderRetcode FilereaderMps::readModelFromFile(const char* filename,
                                                   HighsLp& model) {
  // todo

  // Which parser
  // will be (options.getValue("parser") == MpsParser::new)

  // Initialize arrays

  // call MPSParser::loadProblem(arrays of HighsLp object)
  int objSense;
  double objOffset;
#if defined(Boost_FOUND) && !defined(OLD_PARSER)
  int RtCd = readMPS_FF(filename, model.numRow_, model.numCol_, objSense,
                        objOffset, model.Astart_, model.Aindex_, model.Avalue_,
                        model.colCost_, model.colLower_, model.colUpper_,
                        model.rowLower_, model.rowUpper_);
#else
  std::vector<int> integerColumn;
  int RtCs = readMPS(filename, -1, -1, model.numRow_, model.numCol_, objSense,
                     objOffset, model.Astart_, model.Aindex_, model.Avalue_,
                     model.colCost_, model.colLower_, model.colUpper_,
                     model.rowLower_, model.rowUpper_, integerColumn);
#endif

  return FilereaderRetcode::OKAY;
}

FilereaderRetcode FilereaderMps::writeModelToFile(const char* filename,
                                                  HighsLp model) {
  return FilereaderRetcode::OKAY;
}