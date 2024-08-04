///                                                                           
/// Langulus::Module::Life                                                    
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#pragma once
#include <Langulus.hpp>

using namespace Langulus;

struct Life;
struct Ecosystem;
struct Organism;

#if 1
   #define VERBOSE_LIFE_ENABLED() 1
   #define VERBOSE_LIFE(...)      Logger::Input(Self(), __VA_ARGS__)
   #define VERBOSE_LIFE_TAB(...)  const auto tab = Logger::InputTab(Self(), __VA_ARGS__)
#else
   #define VERBOSE_LIFE_ENABLED() 0
   #define VERBOSE_LIFE(...)      LANGULUS(NOOP)
   #define VERBOSE_LIFE_TAB(...)  LANGULUS(NOOP)
#endif