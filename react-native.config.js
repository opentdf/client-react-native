const path = require('path');

module.exports = {
  dependencies: {
    'mobile-sdk-react-native': {
      root: path.join(__dirname, '..'),
    },
    'react-native-vector-icons': {
      platforms: {
        ios: null,
      },
    },
  },
  
};
