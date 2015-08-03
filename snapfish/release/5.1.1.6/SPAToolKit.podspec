Pod::Spec.new do |s|
  s.name        = 'SPAToolKit'
  s.version     = '5.1.0.1'
  s.license     = 'Commercial'

  s.summary     = 'Snapfish Publisher iOS Toolkit.'

  s.homepage    = 'https://github.com/snapfish/SPAToolKitLIB'
  s.author     = {
      'Snapfish Social Mobile Team' => 'soma-all@snapfish-llc.com'
  }

  s.source       = { :git => 'git@github.com:snapfish/SPAToolKitLIB.git', :tag => s.version }


  s.source_files = 'SPAToolKit.embeddedframework/SPAToolKit.framework/Headers/*.h', 'SPAToolKit.embeddedframework/SPAToolKit.framework/PrivateHeaders/*.h'
  s.resources    = 'SPAToolKit.embeddedframework/SPAToolKit.framework/Resources/*'
  s.preserve_paths = 'SPAToolKit.embeddedframework/SPAToolKit.framework'

  s.dependency   'ADMS_AppLibrary', '0.0.1'
  s.dependency   'Mixpanel', '2.3.6'
  s.dependency   'SFUploader', '>=0.1.0'

  s.frameworks = 'SPAToolKit', 'Security', 'ImageIO', 'SystemConfiguration', 'AddressBook', 'AddressBookUI', 'AssetsLibrary', 'CoreLocation', 'MapKit', 'MessageUI', 'MobileCoreServices', 'QuartzCore', 'UIKit', 'Foundation', 'CoreGraphics', 'CoreText'

  s.requires_arc = false
  s.ios.deployment_target = '7.0'

  s.xcconfig     =  { "FRAMEWORK_SEARCH_PATHS" => '"$(PODS_ROOT)/SPAToolKit/SPAToolKit.embeddedframework"',
                      "HEADER_SEARCH_PATHS"    => '"$(PODS_ROOT)/SPAToolKit/SPAToolKit.embeddedframework/SPAToolKit.framework/**"'}
end
