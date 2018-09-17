const addon = require('./build/Release/addon');

console.log(addon.banana());

addon.curiousBanana((msg) => console.log(`Wow, got this from callback: ${msg}`));