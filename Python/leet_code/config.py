class Config():
    # Your Config Here
    url = "https://leetcode-cn.com/graphql/"
    headers = {
        "content-type": "application/json"
    }
    data = {
            # 获取用户刷题量的请求参数
            'userQuestionProgress': {"operationName": "userQuestionProgress",
                                     "variables": {
                                         "userSlug": ''
                                    },
                                     "query": "query userQuestionProgress($userSlug: String!) {\n  userProfileUserQuestionProgress(userSlug: $userSlug) {\n    numAcceptedQuestions {\n      difficulty\n      count\n      __typename\n    }\n    numFailedQuestions {\n      difficulty\n      count\n      __typename\n    }\n    numUntouchedQuestions {\n      difficulty\n      count\n      __typename\n    }\n    __typename\n  }\n}\n"
            },
            # 获取用户基本信息的请求参数
            'userPublicProfile': {"operationName": "userPublicProfile",
                                  "variables": {
                                      "userSlug": ''
                                  },
                                  "query": "query userPublicProfile($userSlug: String!) {\n  userProfilePublicProfile(userSlug: $userSlug) {\n    username\n    haveFollowed\n    siteRanking\n    profile {\n      userSlug\n      realName\n      aboutMe\n      userAvatar\n      location\n      gender\n      websites\n      skillTags\n      contestCount\n      asciiCode\n      medals {\n        name\n        year\n        month\n        category\n        __typename\n      }\n      ranking {\n        rating\n        ranking\n        currentLocalRanking\n        currentGlobalRanking\n        currentRating\n        ratingProgress\n        totalLocalUsers\n        totalGlobalUsers\n        __typename\n      }\n      skillSet {\n        langLevels {\n          langName\n          langVerboseName\n          level\n          __typename\n        }\n        topics {\n          slug\n          name\n          translatedName\n          __typename\n        }\n        topicAreaScores {\n          score\n          topicArea {\n            name\n            slug\n            __typename\n          }\n          __typename\n        }\n        __typename\n      }\n      socialAccounts {\n        provider\n        profileUrl\n        __typename\n      }\n      __typename\n    }\n    educationRecordList {\n      unverifiedOrganizationName\n      __typename\n    }\n    occupationRecordList {\n      unverifiedOrganizationName\n      jobTitle\n      __typename\n    }\n    submissionProgress {\n      totalSubmissions\n      waSubmissions\n      acSubmissions\n      reSubmissions\n      otherSubmissions\n      acTotal\n      questionTotal\n      __typename\n    }\n    __typename\n  }\n}\n"
            }
    }
    def __init__(self, user_space: str):
        for index,val in self.data.items():
            val['variables']['userSlug'] = user_space
            pass
