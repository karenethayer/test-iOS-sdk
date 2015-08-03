Pod::Spec.new do |s|
  s.name        = 'SnapfishSDKiOS'
  s.version     = '5.1.1.6'
  s.license     = 'Commercial'

  s.summary     = 'Snapfish iOS Print Button.'

  s.homepage    = 'https://github.com/karenethayer/test-iOS-sdk.git'
  s.author     = {
      'Snapfish Mobile SDK Team' => 'iossdk@snapfish-llc.com'
  }

  s.source       = { :git => 'git@github.com:karenethayer/test-iOS-sdk.git', :tag => s.version }


  s.source_files = 'SnapfishSDKiOS.embeddedframework/SnapfishSDKiOS.framework/Headers/*.h', 'SnapfishSDKiOS.embeddedframework/SnapfishSDKiOS.framework/PrivateHeaders/*.h'
  s.resources    = 'SnapfishSDKiOS.embeddedframework/SnapfishSDKiOS.framework/Resources/*'
  s.preserve_paths = 'SnapfishSDKiOS.embeddedframework/SnapfishSDKiOS.framework'

  s.dependency   'ADMS_AppLibrary', '0.0.1'
  s.dependency   'Mixpanel', '2.3.6'

  s.frameworks = 'SnapfishSDKiOS', 'Security', 'ImageIO', 'SystemConfiguration', 'AddressBook', 'AddressBookUI', 'AssetsLibrary', 'CoreLocation', 'MapKit', 'MessageUI', 'MobileCoreServices', 'QuartzCore', 'UIKit', 'Foundation', 'CoreGraphics', 'CoreText'

  s.requires_arc = true
  s.ios.deployment_target = '7.0'

  s.xcconfig     =  { "FRAMEWORK_SEARCH_PATHS" => '"$(PODS_ROOT)/SnapfishSDKiOS/SnapfishSDKiOS.embeddedframework"',
                      "HEADER_SEARCH_PATHS"    => '"$(PODS_ROOT)/SnapfishSDKiOS/SnapfishSDKiOS.embeddedframework/SnapfishSDKiOS.framework/**"'}
end
