⚙️ **Final Features Added**  
Completed weapon customization for the base, barrel, caliber, sight, muzzle, stock, fire selector, and magazine. Added weapon naming and prompts for setting target health from 100–1000 and armor from 0–100.

🧹 **Refactoring Improvements**  
Centralized weapon stat calculations in `RecalculateStats()` and organized component selection into separate functions. Customization uses a temporary weapon copy so changes only apply when confirmed.

🐛 **Bug Fixes**  
Fixed attachment bonuses stacking by resetting stats before recalculation. Initialized unselected components to `None` and corrected a missing `break` that kept the health prompt repeating after valid input.

✨ **Usability Updates**  
Polished menu formatting and added input validation for target settings and weapon names. The range displays remaining ammo, action points, and the current turn, while customization shows updated weapon stats and base hit chance.