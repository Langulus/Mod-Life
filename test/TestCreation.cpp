///                                                                           
/// Langulus::Module::Life                                                    
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#include <Langulus/CppAPI/Life.hpp>
#include <Langulus/Testing.hpp>
#include <Langulus/Allocator.hpp>

using namespace Langulus;
using Things::Thing;


SCENARIO("Ecosystem and Organism creation") {
   static MemoryState memoryState;
   
   GIVEN("Init and shutdown cycles") {
      for (int repeat = 0; repeat != 10; ++repeat) {
         // Create root entity                                          
         auto root = Thing::Root<false>("Life");

         WHEN("Components created via abstractions") {
            auto ecosystem = root.CreatePart<Things::Ecosystem>();
            auto organism = root.CreatePart<Things::Organism>();

            // Update once                                              
            root.Update({});
            root.DumpHierarchy();

            REQUIRE(ecosystem.GetCount() == 1);
            REQUIRE(ecosystem.CastsTo<Things::Ecosystem>(1));
            REQUIRE(ecosystem.IsSparse());

            REQUIRE(organism.GetCount() == 1);
            REQUIRE(organism.CastsTo<Things::Organism>(1));
            REQUIRE(organism.IsSparse());

            REQUIRE(root.GetParts().GetCount() == 2);
         }

      #if LANGULUS_FEATURE(MANAGED_REFLECTION)
         WHEN("Components created via tokens") {
            auto ecosystem = root.CreatePartToken("Ecosystem");
            auto organism = root.CreatePartToken("Organism");

            // Update once                                              
            root.Update({});
            root.DumpHierarchy();

            REQUIRE(ecosystem.GetCount() == 1);
            REQUIRE(ecosystem.CastsTo<Things::Ecosystem>(1));
            REQUIRE(ecosystem.IsSparse());

            REQUIRE(organism.GetCount() == 1);
            REQUIRE(organism.CastsTo<Things::Organism>(1));
            REQUIRE(organism.IsSparse());

            REQUIRE(root.GetParts().GetCount() == 2);
         }
      #endif

         REQUIRE(memoryState.Assert());
         REQUIRE_FALSE(Allocator::CollectGarbage());
      }
   }
}

