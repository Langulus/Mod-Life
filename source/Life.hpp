///                                                                           
/// Langulus::Module::Life                                                    
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#pragma once
#include "Ecosystem.hpp"
#include <Flow/Verbs/Create.hpp>


///                                                                           
///   Life module                                                             
///                                                                           
/// Manages and produces ecosystems                                           
///                                                                           
struct Life final : A::Life {
   LANGULUS(ABSTRACT) false;
   LANGULUS_BASES(A::Life);
   LANGULUS_VERBS(Verbs::Create);

private:
   // List of created input gatherers                                   
   TFactory<Ecosystem> mEcosystems;

public:
   Life(Runtime*, const Many&);

   bool Update(Time);
   void Create(Verb&);
};