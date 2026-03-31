CREATE DATABASE csdb2026
GO

USE csdb2026
GO

SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[BATTLES](
	[NAME] [varchar](20) NOT NULL,
	[DATE] [date] NOT NULL,
 CONSTRAINT [PK_BATTLES] PRIMARY KEY CLUSTERED 
(
	[NAME] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[CLASSES]    Script Date: 6/24/2025 11:32:00 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[CLASSES](
	[CLASS] [varchar](50) NOT NULL,
	[TYPE] [varchar](2) NOT NULL,
	[COUNTRY] [varchar](20) NOT NULL,
	[NUMGUNS] [int] NULL,
	[BORE] [real] NULL,
	[DISPLACEMENT] [int] NULL,
 CONSTRAINT [PK_CLASSES] PRIMARY KEY CLUSTERED 
(
	[CLASS] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[MOVIE]    Script Date: 6/24/2025 11:32:00 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[MOVIE](
	[TITLE] [varchar](255) NOT NULL,
	[YEAR] [int] NOT NULL,
	[LENGTH] [int] NULL,
	[INCOLOR] [char](1) NULL,
	[STUDIONAME] [char](50) NULL,
	[PRODUCERC#] [int] NULL,
 CONSTRAINT [PK_MOVIE] PRIMARY KEY CLUSTERED 
(
	[TITLE] ASC,
	[YEAR] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[MOVIEEXEC]    Script Date: 6/24/2025 11:32:00 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[MOVIEEXEC](
	[CERT#] [int] NOT NULL,
	[NAME] [char](30) NULL,
	[ADDRESS] [varchar](255) NULL,
	[NETWORTH] [bigint] NULL,
 CONSTRAINT [PK_MOVIEEXEC] PRIMARY KEY CLUSTERED 
(
	[CERT#] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[MOVIESTAR]    Script Date: 6/24/2025 11:32:00 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[MOVIESTAR](
	[NAME] [char](30) NOT NULL,
	[ADDRESS] [varchar](255) NULL,
	[GENDER] [char](1) NULL,
	[BIRTHDATE] [date] NULL,
 CONSTRAINT [PK_MOVIESTAR] PRIMARY KEY CLUSTERED 
(
	[NAME] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[OUTCOMES]    Script Date: 6/24/2025 11:32:00 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[OUTCOMES](
	[SHIP] [varchar](50) NOT NULL,
	[BATTLE] [varchar](20) NOT NULL,
	[RESULT] [varchar](10) NOT NULL,
 CONSTRAINT [PK_OUTCOMES] PRIMARY KEY CLUSTERED 
(
	[SHIP] ASC,
	[BATTLE] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[SHIPS]    Script Date: 6/24/2025 11:32:00 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[SHIPS](
	[NAME] [varchar](50) NOT NULL,
	[CLASS] [varchar](50) NOT NULL,
	[LAUNCHED] [int] NULL,
 CONSTRAINT [PK_SHIPS] PRIMARY KEY CLUSTERED 
(
	[NAME] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[STARSIN]    Script Date: 6/24/2025 11:32:00 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[STARSIN](
	[MOVIETITLE] [varchar](255) NOT NULL,
	[MOVIEYEAR] [int] NOT NULL,
	[STARNAME] [char](30) NOT NULL,
 CONSTRAINT [PK_STARSIN] PRIMARY KEY CLUSTERED 
(
	[MOVIETITLE] ASC,
	[MOVIEYEAR] ASC,
	[STARNAME] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[STUDIO]    Script Date: 6/24/2025 11:32:00 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[STUDIO](
	[NAME] [char](50) NOT NULL,
	[ADDRESS] [varchar](255) NULL,
	[PRESC#] [int] NULL,
 CONSTRAINT [PK_STUDIO] PRIMARY KEY CLUSTERED 
(
	[NAME] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
INSERT [dbo].[BATTLES] ([NAME], [DATE]) VALUES (N'Buma', CAST(N'2025-05-06' AS Date))
INSERT [dbo].[BATTLES] ([NAME], [DATE]) VALUES (N'Dogger Bank', CAST(N'1943-07-02' AS Date))
INSERT [dbo].[BATTLES] ([NAME], [DATE]) VALUES (N'Guadalcanal', CAST(N'1942-11-15' AS Date))
INSERT [dbo].[BATTLES] ([NAME], [DATE]) VALUES (N'Lemnos', CAST(N'1943-12-11' AS Date))
INSERT [dbo].[BATTLES] ([NAME], [DATE]) VALUES (N'North Atlantic', CAST(N'1941-05-25' AS Date))
INSERT [dbo].[BATTLES] ([NAME], [DATE]) VALUES (N'North Cape', CAST(N'1943-12-26' AS Date))
INSERT [dbo].[BATTLES] ([NAME], [DATE]) VALUES (N'Surigao Strait', CAST(N'1944-10-25' AS Date))
INSERT [dbo].[BATTLES] ([NAME], [DATE]) VALUES (N'Tsushima', CAST(N'1944-09-08' AS Date))
INSERT [dbo].[BATTLES] ([NAME], [DATE]) VALUES (N'Yellow Sea', CAST(N'1944-03-04' AS Date))
GO
INSERT [dbo].[CLASSES] ([CLASS], [TYPE], [COUNTRY], [NUMGUNS], [BORE], [DISPLACEMENT]) VALUES (N'Bismarck', N'bb', N'Germany', 8, 15, 42000)
INSERT [dbo].[CLASSES] ([CLASS], [TYPE], [COUNTRY], [NUMGUNS], [BORE], [DISPLACEMENT]) VALUES (N'Dardo', N'db', N'Regia Marina', 5, 11, 3500)
INSERT [dbo].[CLASSES] ([CLASS], [TYPE], [COUNTRY], [NUMGUNS], [BORE], [DISPLACEMENT]) VALUES (N'Duma', N'bb', N'Zamibia', 1, 18, 55000)
INSERT [dbo].[CLASSES] ([CLASS], [TYPE], [COUNTRY], [NUMGUNS], [BORE], [DISPLACEMENT]) VALUES (N'Iowa', N'bb', N'USA', 9, 16, 46000)
INSERT [dbo].[CLASSES] ([CLASS], [TYPE], [COUNTRY], [NUMGUNS], [BORE], [DISPLACEMENT]) VALUES (N'Keiser', N'bb', N'Germany', 1, 1, 22222)
INSERT [dbo].[CLASSES] ([CLASS], [TYPE], [COUNTRY], [NUMGUNS], [BORE], [DISPLACEMENT]) VALUES (N'Kongo', N'bc', N'Japan', 8, 14, 32000)
INSERT [dbo].[CLASSES] ([CLASS], [TYPE], [COUNTRY], [NUMGUNS], [BORE], [DISPLACEMENT]) VALUES (N'Maori', N'bb', N'New Zealand', 4, 10, 34000)
INSERT [dbo].[CLASSES] ([CLASS], [TYPE], [COUNTRY], [NUMGUNS], [BORE], [DISPLACEMENT]) VALUES (N'North Carolina', N'bb', N'USA', 12, 16, 37000)
INSERT [dbo].[CLASSES] ([CLASS], [TYPE], [COUNTRY], [NUMGUNS], [BORE], [DISPLACEMENT]) VALUES (N'Renown', N'bc', N'Gt.Britain', 6, 15, 32000)
INSERT [dbo].[CLASSES] ([CLASS], [TYPE], [COUNTRY], [NUMGUNS], [BORE], [DISPLACEMENT]) VALUES (N'Revenge', N'bb', N'Gt.Britain', 8, 15, 29000)
INSERT [dbo].[CLASSES] ([CLASS], [TYPE], [COUNTRY], [NUMGUNS], [BORE], [DISPLACEMENT]) VALUES (N'Tennessee', N'bb', N'USA', 12, 14, 32000)
INSERT [dbo].[CLASSES] ([CLASS], [TYPE], [COUNTRY], [NUMGUNS], [BORE], [DISPLACEMENT]) VALUES (N'Wellington', N'bb', N'New Zealand', 6, 12, 34000)
INSERT [dbo].[CLASSES] ([CLASS], [TYPE], [COUNTRY], [NUMGUNS], [BORE], [DISPLACEMENT]) VALUES (N'Yamato', N'bb', N'Japan', 9, 18, 65000)
INSERT [dbo].[CLASSES] ([CLASS], [TYPE], [COUNTRY], [NUMGUNS], [BORE], [DISPLACEMENT]) VALUES (N'Zuma', N'bb', N'Zamibia', 9, 18, 55000)
GO
INSERT [dbo].[MOVIE] ([TITLE], [YEAR], [LENGTH], [INCOLOR], [STUDIONAME], [PRODUCERC#]) VALUES (N'Empire Strikes Back', 1980, 111, N'Y', N'Fox                                               ', 11)
INSERT [dbo].[MOVIE] ([TITLE], [YEAR], [LENGTH], [INCOLOR], [STUDIONAME], [PRODUCERC#]) VALUES (N'Gone With the Wind', 1938, 238, N'Y', N'MGM                                               ', 14)
INSERT [dbo].[MOVIE] ([TITLE], [YEAR], [LENGTH], [INCOLOR], [STUDIONAME], [PRODUCERC#]) VALUES (N'Logan''s run', 1976, NULL, N'Y', N'Fox                                               ', 15)
INSERT [dbo].[MOVIE] ([TITLE], [YEAR], [LENGTH], [INCOLOR], [STUDIONAME], [PRODUCERC#]) VALUES (N'Pretty Woman', 1990, 119, N'Y', N'Disney                                            ', 16)
INSERT [dbo].[MOVIE] ([TITLE], [YEAR], [LENGTH], [INCOLOR], [STUDIONAME], [PRODUCERC#]) VALUES (N'Star Trek', 1979, 132, N'Y', N'Paramount                                         ', 12)
INSERT [dbo].[MOVIE] ([TITLE], [YEAR], [LENGTH], [INCOLOR], [STUDIONAME], [PRODUCERC#]) VALUES (N'Star Trek: Nemesis', 2002, 116, N'Y', N'Paramount                                         ', 13)
INSERT [dbo].[MOVIE] ([TITLE], [YEAR], [LENGTH], [INCOLOR], [STUDIONAME], [PRODUCERC#]) VALUES (N'Star Wars', 1977, 121, N'Y', N'Fox                                               ', 11)
INSERT [dbo].[MOVIE] ([TITLE], [YEAR], [LENGTH], [INCOLOR], [STUDIONAME], [PRODUCERC#]) VALUES (N'Suburbicon', 2017, 105, N'Y', N'Paramount                                         ', 22)
INSERT [dbo].[MOVIE] ([TITLE], [YEAR], [LENGTH], [INCOLOR], [STUDIONAME], [PRODUCERC#]) VALUES (N'Terms of Endearment', 1983, 132, N'Y', N'MGM                                               ', 17)
INSERT [dbo].[MOVIE] ([TITLE], [YEAR], [LENGTH], [INCOLOR], [STUDIONAME], [PRODUCERC#]) VALUES (N'The Man Who Wasn''t There', 2001, 116, N'N', N'USA Entertainment                                 ', 19)
INSERT [dbo].[MOVIE] ([TITLE], [YEAR], [LENGTH], [INCOLOR], [STUDIONAME], [PRODUCERC#]) VALUES (N'The Midnight Sky', 2020, 118, N'Y', N'Netflix                                           ', 22)
INSERT [dbo].[MOVIE] ([TITLE], [YEAR], [LENGTH], [INCOLOR], [STUDIONAME], [PRODUCERC#]) VALUES (N'The Tender Bar', 2021, 106, N'Y', N'Amazon Studios                                    ', 22)
INSERT [dbo].[MOVIE] ([TITLE], [YEAR], [LENGTH], [INCOLOR], [STUDIONAME], [PRODUCERC#]) VALUES (N'The Usual Suspects', 1995, 106, N'Y', N'MGM                                               ', 18)
INSERT [dbo].[MOVIE] ([TITLE], [YEAR], [LENGTH], [INCOLOR], [STUDIONAME], [PRODUCERC#]) VALUES (N'Wolfs', 2024, 108, N'Y', N'Apple Studios                                     ', 22)
GO
INSERT [dbo].[MOVIEEXEC] ([CERT#], [NAME], [ADDRESS], [NETWORTH]) VALUES (1, N'Robert Iger                   ', N'1720 Kirkwall Road, Azusa, California, USA', 700000000)
INSERT [dbo].[MOVIEEXEC] ([CERT#], [NAME], [ADDRESS], [NETWORTH]) VALUES (2, N'Michael Thorn                 ', N'2443 Sierra Nevada Road, California, USA', 210000000)
INSERT [dbo].[MOVIEEXEC] ([CERT#], [NAME], [ADDRESS], [NETWORTH]) VALUES (3, N'Jonathan Glickman             ', N'1164 Ruthelen St, Los Angeles, California, USA', 375000000)
INSERT [dbo].[MOVIEEXEC] ([CERT#], [NAME], [ADDRESS], [NETWORTH]) VALUES (4, N'Brian Robbins                 ', N'234 22nd St Queens Village, New York, USA', 150000000)
INSERT [dbo].[MOVIEEXEC] ([CERT#], [NAME], [ADDRESS], [NETWORTH]) VALUES (5, N'Frances Berwick               ', N'102 Union St Hanson, Massachusetts, USA', 100000000)
INSERT [dbo].[MOVIEEXEC] ([CERT#], [NAME], [ADDRESS], [NETWORTH]) VALUES (6, N'Merv Griffin                  ', N'246 E Colden Ave, Los Angeles, California, USA', 115000000)
INSERT [dbo].[MOVIEEXEC] ([CERT#], [NAME], [ADDRESS], [NETWORTH]) VALUES (7, N'Stephen Spielberg             ', N'953 Long Hill Rd, Briarcliff Manor, New York, USA', 5300000000)
INSERT [dbo].[MOVIEEXEC] ([CERT#], [NAME], [ADDRESS], [NETWORTH]) VALUES (8, N'Ted Turner                    ', N'9530 92nd St, Ozone Park, New York, USA', 2800000000)
INSERT [dbo].[MOVIEEXEC] ([CERT#], [NAME], [ADDRESS], [NETWORTH]) VALUES (9, N'Debra Winger                  ', N'2202 Plant Ave, Redondo, California, USA', 8000000)
INSERT [dbo].[MOVIEEXEC] ([CERT#], [NAME], [ADDRESS], [NETWORTH]) VALUES (10, N'George Lucas                  ', N'24 Coleman Ave, Borrego Springs, California, USA', 5200000000)
INSERT [dbo].[MOVIEEXEC] ([CERT#], [NAME], [ADDRESS], [NETWORTH]) VALUES (11, N'Gary Kurtz                    ', N'53 Evonne Ave, Rohnert Park, California, USA', 33000000)
INSERT [dbo].[MOVIEEXEC] ([CERT#], [NAME], [ADDRESS], [NETWORTH]) VALUES (12, N'Robert Wise                   ', N'813 Sunset Ave Suisun City, California, USA', 2000000)
INSERT [dbo].[MOVIEEXEC] ([CERT#], [NAME], [ADDRESS], [NETWORTH]) VALUES (13, N'Rick Berman                   ', N'2409 Flatley, Fairfield, California, USA', 21000000)
INSERT [dbo].[MOVIEEXEC] ([CERT#], [NAME], [ADDRESS], [NETWORTH]) VALUES (14, N'David Selznick                ', N'137 Longfellow St, Thousand Oaks, California, USA', 32000000)
INSERT [dbo].[MOVIEEXEC] ([CERT#], [NAME], [ADDRESS], [NETWORTH]) VALUES (15, N'Michael Anderson              ', N'137 Encinitas Ave, Monrovia, California, USA', 13000000)
INSERT [dbo].[MOVIEEXEC] ([CERT#], [NAME], [ADDRESS], [NETWORTH]) VALUES (16, N'Arnon Milchan                 ', N'137 Longfellow St, Thousand Oaks, California, USA', 6400000)
INSERT [dbo].[MOVIEEXEC] ([CERT#], [NAME], [ADDRESS], [NETWORTH]) VALUES (17, N'James Brooks                  ', N'137 Harvard Ave Mill Valley, California, USA', 550000000)
INSERT [dbo].[MOVIEEXEC] ([CERT#], [NAME], [ADDRESS], [NETWORTH]) VALUES (18, N'Bryan Singer                  ', N'2786 Tahquitz Way, Palm Springs, California, USA', 100000000)
INSERT [dbo].[MOVIEEXEC] ([CERT#], [NAME], [ADDRESS], [NETWORTH]) VALUES (19, N'Joel Coen                     ', N'2787 Boardwalk St, Placerville, California, USA', 100000000)
INSERT [dbo].[MOVIEEXEC] ([CERT#], [NAME], [ADDRESS], [NETWORTH]) VALUES (20, N'Chris McCarthy                ', N'4 Ashdown Pl, Half Moon Bay, California, USA', 6000000)
INSERT [dbo].[MOVIEEXEC] ([CERT#], [NAME], [ADDRESS], [NETWORTH]) VALUES (21, N'Zack Van Amburg               ', N'3215 Overland Ave, Los Angeles, California, USA', 283000000)
INSERT [dbo].[MOVIEEXEC] ([CERT#], [NAME], [ADDRESS], [NETWORTH]) VALUES (22, N'George Clooney                ', N'8500 Beverly 6692 Blvd, Los Angeles, California, USA', 500000000)
INSERT [dbo].[MOVIEEXEC] ([CERT#], [NAME], [ADDRESS], [NETWORTH]) VALUES (23, N'Ted Sarandos                  ', N'114 Morgan Ave, Los Angeles, California, USA', 200000000)
INSERT [dbo].[MOVIEEXEC] ([CERT#], [NAME], [ADDRESS], [NETWORTH]) VALUES (24, N'Mike Hopkins                  ', N'6736 Sherbourne Dr, Los Angeles, California, USA', 12300000)
GO
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Alec Baldwin                  ', N'2211 Mcpherson Rd, Perris, California, USA', N'M', CAST(N'1958-04-03' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Alec Guinness                 ', N'12 Guild Street, London, UK', N'M', CAST(N'1914-04-02' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Amy Ryan                      ', N'36 County 60, Vermontville, New York, USA', N'F', CAST(N'1968-05-03' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Anthony Daniels               ', N'6736 S Sherbourne Dr, Los Angeles, California, USA', N'M', CAST(N'1946-02-21' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Austin Abrams                 ', N'90 Jefferson St #APT 3FL Troy, New York, USA', N'M', CAST(N'1996-09-02' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Ben Affleck                   ', N'1874 Cornelia St, Ridgewood, New York, USA', N'M', CAST(N'1972-08-15' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Benicio del Toro              ', N'9838 57th Ave #APT 17A, Corona, New York, USA', N'M', CAST(N'1967-02-19' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Billy Dee Williams            ', N'9283 W 85th Pl, Los Angeles, California, USA', N'M', CAST(N'1937-04-06' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Brad Pitt                     ', N'9400 Normandie Ave, Los Angeles, California, USA', N'M', CAST(N'1963-12-18' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Carrie Fisher                 ', N'5960 W 85th Pl, Los Angeles, California, USA', N'F', CAST(N'1956-10-28' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Chazz Palminteri              ', N'1404 W 105th St, Los Angeles, California, USA', N'M', CAST(N'1952-05-15' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Danny DeVito                  ', N'7609 Mckinley Ave, Los Angeles, California, USA', N'M', CAST(N'1944-11-17' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'David Prowse                  ', N'218 Donal Early Way, Bristol BS10 5NB, UK', N'M', CAST(N'1935-07-01' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Debra Winger                  ', N'2202 Plant Ave, Redondo, California, USA', N'F', CAST(N'1955-05-16' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'DeForest Kelley               ', N'7609 Mckinley Ave, Los Angeles, California, USA', N'M', CAST(N'1920-01-20' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Felicity Jones                ', N'1219 W 54th St, Los Angeles, California, USA', N'F', CAST(N'1983-10-17' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Frank Oz                      ', N'6 Oulton Ave, Belmont, Hereford HR2 7YX, UK', N'M', CAST(N'1944-05-25' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Gabriel Byrne                 ', N'4134 Crescent St, Long Island, New York, USA', N'M', CAST(N'1950-05-12' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'George Clooney                ', N'8500 Beverly Blvd, Los Angeles, California, USA', N'M', CAST(N'1961-05-06' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'George Takei                  ', N'6736 S Sherbourne Dr, Los Angeles, California, USA', N'M', CAST(N'1937-04-20' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Harrison Ford                 ', N'1231 Woodside Rd, Sacramento, California, USA', N'M', CAST(N'1942-07-13' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Jack Nicholson                ', N'2912 Nisqually Rd, Apple Valley, California, USA', N'M', CAST(N'1937-04-22' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'James Doohan                  ', N'2600 S Hoover St, Los Angeles, California, USA', N'M', CAST(N'1920-03-03' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Jane Fonda                    ', N'2203 Portola Rd, Westlake Village, California, USA', N'F', CAST(N'1937-12-21' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Jonathan Frakes               ', N'1032 W 91st St, Los Angeles, California, USA', N'M', CAST(N'1952-08-19' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Julia Roberts                 ', N'680 E 47th St, Los Angeles, California, USA', N'F', CAST(N'1967-10-28' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Julianne Moore                ', N'920 S Hobart Blvd, Los Angeles, California, USA', N'F', CAST(N'1960-12-03' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Kenny Baker                   ', N'21 Colmore Row, Birmingham B3 2BH, UK', N'M', CAST(N'1934-08-24' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Kevin Pollak                  ', N'70 Barker St, Mount Kisco, New York, USA', N'M', CAST(N'1957-10-30' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Kevin Spacey                  ', N'4845 Transit Rd #I10, Depew, New York, USA', N'M', CAST(N'1959-07-26' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Kim Basinger                  ', N'1512 Acacia Ave, Ripon, California, USA', N'F', CAST(N'1953-12-08' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Leonard Nimoy                 ', N'680 E 47th St, Los Angeles, California, USA', N'M', CAST(N'1931-03-26' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Lily Rabe                     ', N'7609 Mckinley Ave, Los Angeles, California, USA', N'F', CAST(N'1982-06-29' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Majel Barrett                 ', N'1000 S Westgate Ave, Los Angeles, California, USA', N'F', CAST(N'1932-02-23' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Mark Hamill                   ', N'8500 Beverly, Los Angeles, California, USA', N'M', CAST(N'1951-09-25' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Matt Damon                    ', N'880 N Alameda St, Los Angeles, California, USA', N'M', CAST(N'1970-10-08' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Nichelle Nichols              ', N'5960 W 85th Pl, Los Angeles, California, USA', N'f', CAST(N'1932-12-28' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Noah Jupe                     ', N'276 James Wood, Los Angeles, California, USA', N'M', CAST(N'2005-02-25' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Oscar Isaac                   ', N'35 Overland Ave, Los Angeles, California, USA', N'M', CAST(N'1979-03-09' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Patrick Stewart               ', N'1209 W 121st St, Los Angeles, California, USA', N'M', CAST(N'1940-07-13' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Persis Khambatta              ', N'5960 W 85th Pl, Los Angeles, California, USA', N'F', CAST(N'1948-10-02' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Pete Postlethwaite            ', N'7618 69th Pl, Ridgewood, New York, USA', N'M', CAST(N'1946-02-07' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Peter Cushing                 ', N'233 London Rd, Addington, Kent, UK', N'M', CAST(N'1913-05-26' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Peter Mayhew                  ', N'2300 E 10th St, Weslaco, Texas, USA', N'M', CAST(N'1944-05-19' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Poorna Jagannathan            ', N'11 Mallard Way, Wynantskill, New York, USA', N'F', CAST(N'1972-12-22' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Richard Gere                  ', N'9400 S Normandie Ave, Los Angeles, California, USA', N'M', CAST(N'1942-08-31' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Robert De Niro                ', N'5960 85th Pl, Los Angeles, California, USA', N'M', CAST(N'1943-08-17' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Sandra Bullock                ', N'1936 Una Ct, Fremont, California, USA', N'F', CAST(N'1964-07-26' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Shirley MacLean               ', N'909-1/2 E 49th St, Los Angeles, California, USA', N'F', CAST(N'1934-04-23' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Stephen Baldwin               ', N'5723 Morgan Ave, Los Angeles, California, USA', N'M', CAST(N'1966-05-12' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Stephen Collins               ', N'246 E Colden Ave, Los Angeles, California, USA', N'M', CAST(N'1947-10-01' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Tye Sheridan                  ', N'930 E 224th St, Bronx, New York, USA', N'M', CAST(N'1996-11-11' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'Walter Koenig                 ', N'3215 Overland Ave, Los Angeles, California, USA', N'M', CAST(N'1936-09-14' AS Date))
INSERT [dbo].[MOVIESTAR] ([NAME], [ADDRESS], [GENDER], [BIRTHDATE]) VALUES (N'William Shatner               ', N'909-1/2 E 49th St, Los Angeles, California, USA', N'M', CAST(N'1931-03-22' AS Date))
GO
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'Bismarck', N'North Atlantic', N'sunk')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'Bismarck', N'Yellow Sea', N'ok')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'California', N'Dogger Bank', N'ok')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'California', N'Guadalcanal', N'damaged')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'California', N'Surigao Strait', N'ok')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'California', N'Yellow Sea', N'ok')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'Duke of York', N'North Cape', N'ok')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'Duma', N'Buma', N'damaged')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'Fuso', N'Surigao Strait', N'sunk')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'Hood', N'North Atlantic', N'sunk')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'King George V', N'Dogger Bank', N'ok')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'King George V', N'North Atlantic', N'ok')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'Kirishima', N'Guadalcanal', N'sunk')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'Missouri', N'Dogger Bank', N'damaged')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'Prince of Wales', N'Dogger Bank', N'damaged')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'Prince of Wales', N'North Atlantic', N'damaged')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'Rodney', N'North Atlantic', N'ok')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'Rodney', N'Tsushima', N'ok')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'Schamhorst', N'North Cape', N'sunk')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'South Dakota', N'Dogger Bank', N'ok')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'South Dakota', N'Guadalcanal', N'damaged')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'South Dakota', N'Yellow Sea', N'ok')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'Tennessee', N'Surigao Strait', N'ok')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'Washington', N'Guadalcanal', N'ok')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'Wellington', N'North Cape', N'ok')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'Wellington', N'Yellow Sea', N'ok')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'West Virginia', N'Surigao Strait', N'ok')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'Wisconsin', N'Dogger Bank', N'ok')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'Yamashiro', N'Surigao Strait', N'sunk')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'Yamato', N'Tsushima', N'damaged')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'Yamato', N'Yellow Sea', N'damaged')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'Yanashiro', N'Tsushima', N'ok')
INSERT [dbo].[OUTCOMES] ([SHIP], [BATTLE], [RESULT]) VALUES (N'Yanashiro', N'Yellow Sea', N'damaged')
GO
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Bismarck', N'North Carolina', 1911)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'California', N'Tennessee', 1921)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Duke of York', N'Renown', 1916)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Duma', N'Duma', 1942)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Fuso', N'Iowa', 1940)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Haruna', N'Kongo', 1916)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Hiei', N'Kongo', 1914)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Hood', N'Iowa', 1940)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Iowa', N'Iowa', 1943)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'King George V', N'Iowa', 1938)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Kirishima', N'Kongo', 1915)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Kongo', N'Kongo', 1913)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Missouri', N'Iowa', 1944)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Musashi', N'Yamato', 1942)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'New Jersey', N'Iowa', 1943)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'North Carolina', N'North Carolina', 1941)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Prince of Wales', N'North Carolina', 1937)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Ramillies', N'Revenge', 1917)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Renown', N'Renown', 1916)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Repulse', N'Renown', 1916)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Resolution', N'Renown', 1916)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Revenge', N'Revenge', 1916)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Rodney', N'Yamato', 1915)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Royal Oak', N'Revenge', 1916)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Royal Sovereign', N'Revenge', 1916)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Schamhorst', N'North Carolina', 1917)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'South Dakota', N'North Carolina', 1941)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Tennessee', N'Tennessee', 1920)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Washington', N'North Carolina', 1941)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Wellington', N'Wellington', 1921)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'West Virginia', N'Iowa', 1942)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Wisconsin', N'Iowa', 1944)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Yamashiro', N'Yamato', 1941)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Yamato', N'Yamato', 1941)
INSERT [dbo].[SHIPS] ([NAME], [CLASS], [LAUNCHED]) VALUES (N'Yanashiro', N'Yamato', 1918)
GO
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Empire Strikes Back', 1980, N'Anthony Daniels               ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Empire Strikes Back', 1980, N'Billy Dee Williams            ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Empire Strikes Back', 1980, N'Carrie Fisher                 ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Empire Strikes Back', 1980, N'David Prowse                  ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Empire Strikes Back', 1980, N'Frank Oz                      ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Empire Strikes Back', 1980, N'Harrison Ford                 ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Empire Strikes Back', 1980, N'Kenny Baker                   ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Empire Strikes Back', 1980, N'Mark Hamill                   ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Empire Strikes Back', 1980, N'Peter Mayhew                  ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Pretty Woman', 1990, N'Julia Roberts                 ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Pretty Woman', 1990, N'Richard Gere                  ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Star Trek', 1979, N'DeForest Kelley               ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Star Trek', 1979, N'George Takei                  ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Star Trek', 1979, N'James Doohan                  ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Star Trek', 1979, N'Leonard Nimoy                 ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Star Trek', 1979, N'Majel Barrett                 ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Star Trek', 1979, N'Nichelle Nichols              ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Star Trek', 1979, N'Persis Khambatta              ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Star Trek', 1979, N'Stephen Collins               ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Star Trek', 1979, N'Walter Koenig                 ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Star Trek', 1979, N'William Shatner               ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Star Trek: Nemesis', 2002, N'Jonathan Frakes               ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Star Trek: Nemesis', 2002, N'Patrick Stewart               ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Star Wars', 1977, N'Alec Guinness                 ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Star Wars', 1977, N'Carrie Fisher                 ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Star Wars', 1977, N'Harrison Ford                 ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Star Wars', 1977, N'Mark Hamill                   ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Star Wars', 1977, N'Peter Cushing                 ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Suburbicon', 2017, N'Julianne Moore                ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Suburbicon', 2017, N'Matt Damon                    ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Suburbicon', 2017, N'Noah Jupe                     ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Suburbicon', 2017, N'Oscar Isaac                   ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Terms of Endearment', 1983, N'Danny DeVito                  ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Terms of Endearment', 1983, N'Debra Winger                  ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Terms of Endearment', 1983, N'Jack Nicholson                ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Terms of Endearment', 1983, N'Shirley MacLean               ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'The Midnight Sky', 2020, N'Felicity Jones                ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'The Midnight Sky', 2020, N'George Clooney                ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'The Tender Bar', 2021, N'Ben Affleck                   ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'The Tender Bar', 2021, N'Lily Rabe                     ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'The Tender Bar', 2021, N'Tye Sheridan                  ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'The Usual Suspects', 1995, N'Benicio del Toro              ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'The Usual Suspects', 1995, N'Chazz Palminteri              ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'The Usual Suspects', 1995, N'Gabriel Byrne                 ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'The Usual Suspects', 1995, N'Kevin Pollak                  ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'The Usual Suspects', 1995, N'Kevin Spacey                  ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'The Usual Suspects', 1995, N'Pete Postlethwaite            ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'The Usual Suspects', 1995, N'Stephen Baldwin               ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Wolfs', 2024, N'Amy Ryan                      ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Wolfs', 2024, N'Austin Abrams                 ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Wolfs', 2024, N'Brad Pitt                     ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Wolfs', 2024, N'George Clooney                ')
INSERT [dbo].[STARSIN] ([MOVIETITLE], [MOVIEYEAR], [STARNAME]) VALUES (N'Wolfs', 2024, N'Poorna Jagannathan            ')
GO
INSERT [dbo].[STUDIO] ([NAME], [ADDRESS], [PRESC#]) VALUES (N'Amazon Studios                                    ', N'121 Albright Way Los Gatos, California, USA', 24)
INSERT [dbo].[STUDIO] ([NAME], [ADDRESS], [PRESC#]) VALUES (N'Apple Studios                                     ', N'8600 Hayden Place, Culver City, California, USA', 21)
INSERT [dbo].[STUDIO] ([NAME], [ADDRESS], [PRESC#]) VALUES (N'Disney                                            ', N'500 South Buena Vista, Burbank, California, USA', 1)
INSERT [dbo].[STUDIO] ([NAME], [ADDRESS], [PRESC#]) VALUES (N'Fox                                               ', N'10201 Pico Boulevard, Los Angeles, California, USA', 2)
INSERT [dbo].[STUDIO] ([NAME], [ADDRESS], [PRESC#]) VALUES (N'MGM                                               ', N'245 North Beverly Drive, Beverly Hills, California, USA', 3)
INSERT [dbo].[STUDIO] ([NAME], [ADDRESS], [PRESC#]) VALUES (N'MTV                                               ', N'1515 Broadway, Times Square, Manhattan, New York, USA', 20)
INSERT [dbo].[STUDIO] ([NAME], [ADDRESS], [PRESC#]) VALUES (N'Netflix                                           ', N'121 Albright Way Los Gatos, California, USA', 23)
INSERT [dbo].[STUDIO] ([NAME], [ADDRESS], [PRESC#]) VALUES (N'Paramount                                         ', N'846 University Avenue, Norwood, Massachusetts, USA', 4)
INSERT [dbo].[STUDIO] ([NAME], [ADDRESS], [PRESC#]) VALUES (N'USA Entertainment                                 ', N'30 Rockefeller Plaza, New York, NY 10112, USA', 5)
GO
ALTER TABLE [dbo].[MOVIE]  WITH CHECK ADD  CONSTRAINT [FK_MOVIE_MOVIEEXEC] FOREIGN KEY([PRODUCERC#])
REFERENCES [dbo].[MOVIEEXEC] ([CERT#])
GO
ALTER TABLE [dbo].[MOVIE] CHECK CONSTRAINT [FK_MOVIE_MOVIEEXEC]
GO
ALTER TABLE [dbo].[MOVIE]  WITH CHECK ADD  CONSTRAINT [FK_MOVIE_STUDIO] FOREIGN KEY([STUDIONAME])
REFERENCES [dbo].[STUDIO] ([NAME])
GO
ALTER TABLE [dbo].[MOVIE] CHECK CONSTRAINT [FK_MOVIE_STUDIO]
GO
ALTER TABLE [dbo].[OUTCOMES]  WITH CHECK ADD  CONSTRAINT [FK_OUTCOMES_BATTLES] FOREIGN KEY([BATTLE])
REFERENCES [dbo].[BATTLES] ([NAME])
GO
ALTER TABLE [dbo].[OUTCOMES] CHECK CONSTRAINT [FK_OUTCOMES_BATTLES]
GO
ALTER TABLE [dbo].[OUTCOMES]  WITH CHECK ADD  CONSTRAINT [FK_OUTCOMES_SHIPS] FOREIGN KEY([SHIP])
REFERENCES [dbo].[SHIPS] ([NAME])
GO
ALTER TABLE [dbo].[OUTCOMES] CHECK CONSTRAINT [FK_OUTCOMES_SHIPS]
GO
ALTER TABLE [dbo].[SHIPS]  WITH CHECK ADD  CONSTRAINT [FK_SHIPS_CLASSES] FOREIGN KEY([CLASS])
REFERENCES [dbo].[CLASSES] ([CLASS])
GO
ALTER TABLE [dbo].[SHIPS] CHECK CONSTRAINT [FK_SHIPS_CLASSES]
GO
ALTER TABLE [dbo].[STARSIN]  WITH CHECK ADD  CONSTRAINT [FK_STARSIN_MOVIE] FOREIGN KEY([MOVIETITLE], [MOVIEYEAR])
REFERENCES [dbo].[MOVIE] ([TITLE], [YEAR])
GO
ALTER TABLE [dbo].[STARSIN] CHECK CONSTRAINT [FK_STARSIN_MOVIE]
GO
ALTER TABLE [dbo].[STARSIN]  WITH CHECK ADD  CONSTRAINT [FK_STARSIN_MOVIESTAR] FOREIGN KEY([STARNAME])
REFERENCES [dbo].[MOVIESTAR] ([NAME])
GO
ALTER TABLE [dbo].[STARSIN] CHECK CONSTRAINT [FK_STARSIN_MOVIESTAR]
GO


