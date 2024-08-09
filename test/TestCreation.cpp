///                                                                           
/// Langulus::Module::Life                                                    
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#include "Main.hpp"
#include <Langulus/Life.hpp>
#include <catch2/catch.hpp>


/// See https://github.com/catchorg/Catch2/blob/devel/docs/tostring.md        
CATCH_TRANSLATE_EXCEPTION(::Langulus::Exception const& ex) {
   const Text serialized {ex};
   return ::std::string {Token {serialized}};
}

SCENARIO("Ecosystem and Organism creation", "[life]") {
   static Allocator::State memoryState;
   
   for (int repeat = 0; repeat != 10; ++repeat) {
      GIVEN(std::string("Init and shutdown cycle #") + std::to_string(repeat)) {
         // Create root entity                                          
         auto root = Thing::Root<false>("Life");

         WHEN("Components created via abstractions") {
            auto ecosystem = root.CreateUnit<A::Ecosystem>();
            auto organism = root.CreateUnit<A::Organism>();

            // Update once                                              
            root.Update(Time::zero());
            root.DumpHierarchy();

            REQUIRE(ecosystem.GetCount() == 1);
            REQUIRE(ecosystem.CastsTo<A::Ecosystem>(1));
            REQUIRE(ecosystem.IsSparse());

            REQUIRE(organism.GetCount() == 1);
            REQUIRE(organism.CastsTo<A::Organism>(1));
            REQUIRE(organism.IsSparse());

            REQUIRE(root.GetUnits().GetCount() == 2);
         }

      #if LANGULUS_FEATURE(MANAGED_REFLECTION)
         WHEN("Components created via tokens") {
            auto ecosystem = root.CreateUnitToken("Ecosystem");
            auto organism = root.CreateUnitToken("Organism");

            // Update once                                              
            root.Update(Time::zero());
            root.DumpHierarchy();

            REQUIRE(ecosystem.GetCount() == 1);
            REQUIRE(ecosystem.CastsTo<A::Ecosystem>(1));
            REQUIRE(ecosystem.IsSparse());

            REQUIRE(organism.GetCount() == 1);
            REQUIRE(organism.CastsTo<A::Organism>(1));
            REQUIRE(organism.IsSparse());

            REQUIRE(root.GetUnits().GetCount() == 2);
         }
      #endif

         // Check for memory leaks after each cycle                     
         REQUIRE(memoryState.Assert());
      }
   }
}

