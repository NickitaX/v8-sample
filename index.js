const addon = require('./build/Release/addon');

console.log(addon.hi());

addon.call((msg) => console.log(`Wow, got this from callback: ${msg}`));