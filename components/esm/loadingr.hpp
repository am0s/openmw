#ifndef _ESM_INGR_H
#define _ESM_INGR_H

#include "esm_reader.hpp"

namespace ESM {

/*
 * Alchemy ingredient
 */

struct Ingredient
{
  struct IRDTstruct
  {
    float weight;
    int value;
    int effectID[4];    // Effect, 0 or -1 means none
    int skills[4];      // SkillEnum related to effect
    int attributes[4];  // Attribute related to effect
  };

  IRDTstruct data;
  std::string name, model, icon, script;

  void load(ESMReader &esm)
  {
    model = esm.getHNString("MODL");
    name = esm.getHNString("FNAM");
    esm.getHNT(data, "IRDT", 56);
    script = esm.getHNOString("SCRI");
    icon = esm.getHNOString("ITEX");
  }
};
}
#endif
